#include<iostream>
using namespace std;

int main()
{
	string s;
	cin >>s;
	if(s[0] == 'R' && s[1] == 'R' && s[2] == 'R')
		cout <<"3\n";
	else if(s[0] == 'R' && s[1] == 'R' || 
		s[1] == 'R' && s[2] == 'R')
		cout <<"2\n";
	else if(s[0] == 'R' || s[1] == 'R' || s[2] == 'R')
		cout <<"1\n";
	else 
		cout <<"0\n";

}
