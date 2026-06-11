#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}


int main()
{
	int a;
	ll b, n;
	ll x;

	cin >> a >> b >> n;
	x = min(n, b - 1);
	ll max = floor(a * x / b) - a * floor(x / b);

	cout << max << endl;
	return 0;
}