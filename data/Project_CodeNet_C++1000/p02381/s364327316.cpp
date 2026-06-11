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
	while(1)
	{
		int n;
		double m;
		vector<int> vs;
		double sigma;
		
		cin >> n;
		cin.ignore();
		if (n == 0)break;

		string temp;
		getline(cin, temp);
		string tmp;
		istringstream iss(temp);
		while (!iss.eof())
		{
			int t;
			iss >> t;
			vs.push_back(t);
			iss.ignore();
		}

		m = accumulate(vs.begin(), vs.end(), 0.0) / n;
		double ts = 0.0;
		for (int i = 0; i < n; i++)
		{
			ts += (pow(vs.at(i) - m, 2.0)) / n;
		}
		sigma = sqrt(ts);
		cout << fixed << setprecision(8) << sigma << endl;
	}
	return 0;
}