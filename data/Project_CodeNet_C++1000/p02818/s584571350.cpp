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
	ll A, B, K;
	cin >> A >> B >> K;

	ll remain = max(K - A, (ll)0);
	A = max(A - K, (ll)0);
	B = max(B - remain, (ll)0);

	cout << A << endl;
	cout << B << endl;
	return 0;
}