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
	ll N, A, B;
	cin >> N >> A >> B;

	ll num = N / (A + B);
	ll count = num * A;

	ll remain = N - (num * (A + B));
	if (remain - A > 0)
	{
		count += A;
	}
	else
	{
		count += remain;
	}

	cout << count << endl;

	return 0;
}