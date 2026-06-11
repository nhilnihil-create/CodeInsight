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
    int a, b, c;
    cin >> a >> b >> c;

	string result = "No";

	if (a == b && b != c)
	{
		result = "Yes";
	}
	
	if (a == c && a != b)
	{
		result = "Yes";
	}

	if (b == c && a != b)
	{
		result = "Yes";
	}

	cout << result << endl;
    return 0;
}