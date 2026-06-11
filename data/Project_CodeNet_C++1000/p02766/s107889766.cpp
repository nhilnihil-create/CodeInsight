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
	long N, K;
	cin >> N >> K;

	long digitCount = 1;
	while (true)
	{
		long calcNum = pow(K, digitCount);
		if (calcNum > N)
		{
			break;
		}
		digitCount++;
	}

	cout << digitCount << endl;
	return 0;
}