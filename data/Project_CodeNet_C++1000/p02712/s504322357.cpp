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

	ll sum = 0;
	for (size_t i = 1; i <= N; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			continue;
		}

		sum += i;
	}

	cout << sum << endl;
	return 0;
}