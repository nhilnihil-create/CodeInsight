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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	string result;
	for (size_t i = 0; i < n * 2; i++)
	{
		result += (i % 2 == 0) ? s[i / 2] : t[i / 2];
	}

	cout << result << endl;
	return 0;
}