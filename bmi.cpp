#include <iostream>	//there was not enough time for me to do data validation but ideally you would loop through all characters 
#include <fstream>	//and check if each character is between 0 and 9, and to direct the user to an error message when needed
#include <string>

using namespace std;

int inch2feet(int x)	//function for converting because consistency
{
	if (x >-1)
	return(x/12);
}

int ounces2pounds(int x)
{
	if (x > -1)
    	return(x/16);	//ounces to pounds means divided by 16, not multiplied (if i am doing maths right)
}

int stones2pounds(int x)
{	if (x > -1)
    	return(x*14);
}

double weight2kg(int stones, int pounds, int ounces)
{	if stones > -1)
    return (stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2;
}

double height2metres(int feet, int inches)
{
    return(feet + inch2feet(inches) / 3.82);	//changed so that inches are included
}

char categorise(double kg, double metre)
{
    double bmi = kg*kg/metre;
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi<=26)
        cat='B';
    else if (bmi<=30)	//if equal to or less than 30, not 300
        cat='C';
    else
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet, inches;
    double kg, m;
    char cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (!f_in.eof())
    {
    	f_in >> person_id >> pounds >> stones >> ounces >> feet >> inches;
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),int(inches));
        cat=categorise(kg,m);
	f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    process_data(argv[1], argv[2]);
}
