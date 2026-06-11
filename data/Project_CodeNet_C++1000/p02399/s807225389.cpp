#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <iomanip>

//#include <map>

using namespace std;

void spritStr(string str, vector<string>& v)
{
	while (str.find(' ') != -1)
	{
		v.push_back(str.substr(0, str.find(' ')));
		str.erase(0, str.find(' ') + 1);
	}
	v.push_back(str);
}

int main()
{
	string st;
	getline(cin, st);

	vector<string> vStr;
	spritStr(st, vStr);

	unsigned long a, b, ansI, ansM;
	double ansD = 0.0;
	a = stol(vStr[0]);
	b = stol(vStr[1]);

	ansI = a / b;
	ansM = a % b;
	ansD = static_cast<double>(a) / static_cast<double>(b);

	cout << ansI << " " << ansM << " " << fixed << setprecision(8) << ansD << endl;

	return 0;
}