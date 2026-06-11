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
	int X;
	cin >> X;

	int count1 = X / 500;
	int count2 = (X - (count1 * 500)) / 5;

	cout << (count1 * 1000 + count2 * 5) << endl;

	return 0;
}