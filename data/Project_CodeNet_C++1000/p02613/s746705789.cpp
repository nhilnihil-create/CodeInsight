#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;


int main()
{
	int a, ac=0, wa=0, tle=0, re=0;
	cin >> a;
	for(int i=0; i<a; i++)
	{
		string str;
		cin >> str;
		if(str == "AC")
		{
			ac ++;
		}
		else if(str == "WA")
		{
			wa ++;
		}
		else if(str == "TLE")
		{
			tle ++;
		}
		else if(str == "RE")
		{
			re ++;
		}
	}
	cout << "AC x " << ac << '\n';
	cout << "WA x " << wa << '\n';
	cout << "TLE x " << tle << '\n';
	cout << "RE x " << re;
}

