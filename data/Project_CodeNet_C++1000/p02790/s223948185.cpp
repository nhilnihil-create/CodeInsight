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
	string a, b;
	cin >> a >> b;

	string A;
	for (size_t i = 0; i < atoi(b.c_str()); i++)
	{
		A += a;
	}

	string B;
	for (size_t i = 0; i < atoi(a.c_str()); i++)
	{
		B += b;
	}

	string result = A > B ? B : A;

	cout << result<< endl;
	return 0;
}