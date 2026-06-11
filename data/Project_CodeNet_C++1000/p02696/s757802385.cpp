#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
	ll a, b, n;
	cin >> a >> b >> n;

	n = min(b - 1, n);

	ll max = floor(a * n / b) - a * floor(n / b);

	cout << max << endl;
	return 0;
}