#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;

	long long ans = 0;

	if (n / k)
	{
		n %= k;
	}

	if (n < abs(n - k))	cout << n << endl;
	else cout << abs(n - k) << endl;

	return 0;
}