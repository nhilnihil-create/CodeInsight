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
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}


int main()
{
	ll n, a, b;
	cin >> n >> a >> b;
	ll r1, r2;

	r1 = n / (a + b) *a;
	r2 = min(n % (a + b), a);

	cout << r1 + r2 << endl;

	return 0;
}