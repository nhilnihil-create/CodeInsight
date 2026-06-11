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
    int N;
	cin >> N;

	int n = N % 10;
	if (n == 2 || n == 4 || n == 5 || n == 7 || n == 9)
	{
		cout << "hon" << endl;
		return 0;
	}
	else if (n == 0 || n == 1 || n == 6 || n == 8)
	{
		cout << "pon" << endl;
		return 0;
	}

	cout << "bon" << endl;

	return 0;
}