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
	string S;
	cin >> S;

	string a = S.substr(0, (S.length() - 1) / 2);
	string b = S.substr((S.length() + 3) / 2 - 1);

	cout << (a == b ? "Yes" : "No") << endl;

	return 0;
}