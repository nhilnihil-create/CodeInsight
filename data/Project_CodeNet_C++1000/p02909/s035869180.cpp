#include<iostream>
#include<string>
using namespace std;
int main()
{
	char S;
	string x[3];
	x[0] = "Sunny";
	x[1] = "Cloudy";
	x[2] = "Rainy";
	cin >> S;
	if (S == 's' || S == 'S')
		cout << x[1];
	else if (S == 'c' || S == 'C')
		cout << x[2];
	else
		cout << x[0];

}