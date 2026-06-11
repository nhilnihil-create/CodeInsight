#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <numeric>
#include <regex>
#include <locale>
#include <fstream>
#include <stdlib.h>
#include <cctype>

//#include <map>

using namespace std;

int main()
{
	int n;
	vector<int> vx, vy;

	cin >> n;
	cin.ignore();

	string temp;
	{
		getline(cin, temp);
		istringstream iss(temp);
		while (!iss.eof())
		{
			int t;
			iss >> t;
			vx.push_back(t);
			iss.ignore();
		}
	}
	{
		getline(cin, temp);
		istringstream iss(temp);
		while (!iss.eof())
		{
			int t;
			iss >> t;
			vy.push_back(t);
			iss.ignore();
		}
	}

	double D = 0.0;
	double d = 0;
	for (double p = 1.0; p <= 3.0; p += 1.0)
	{
		d = 0.0;
		for (int i = 0; i < n; i++)
		{
			double dd = abs(vx.at(i) - vy.at(i));
			double ddd = pow(dd, p);
			d += pow(abs(vx.at(i) - vy.at(i)) * 1.0, p);
		}
		D = pow(d, 1.0 / p);
		cout << fixed << setprecision(8) << D << endl;
	}

	d = 0.0;
	for (int i = 0; i < n; i++)
	{
		d = max(d, abs(vx.at(i) - vy.at(i)) * 1.0);
	}
	cout << fixed << setprecision(8) << d << endl;
	return 0;
}