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
	int A, B, C, K;
	cin >> A >> B >> C >> K;

	int sum = 0;
	if(K - A > 0)
	{
		sum += A;
	}
	else
	{
		sum += K;
	}

	K -= A;

	if(K > 0)
	{
		K -= B;
	}

	if(K > 0)
	{
		if(K - C > 0)
		{
			sum -= C;
		}
		else
		{
			sum -= K;
		}
	}

	cout << sum << endl;

	return 0;
}