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
	string x;
	cin >> x;

	bool result = x[0] == '7' || x[1] == '7' || x[2] == '7';

	printf(result ? "Yes" : "No");
	return 0;
}