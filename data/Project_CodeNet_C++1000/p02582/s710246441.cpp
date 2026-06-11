#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	string s;
	int a=0, b=0;
	cin >> s;
	for(int i=0; i<3; i++)
	{
		if(s[i] == 'R')
		{
			a++;
			b=a;
		}
		else if(s[i] != 'R')
		{
			a=0;
		}
	}
	cout << b;
}

