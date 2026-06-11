#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cctype>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

const int mod = 1000000007;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ll long long

int main()
{
    string S, T;
	cin >> S >> T;

	if (T.length() == S.length() + 1)
	{
		string str = T.substr(0, S.length());
		if (str == S)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}