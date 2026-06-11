#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

signed main(void)
{
	int a;
	double b;
	cin >> a >> b;
	int c;
	c = (b * 100.0) + 0.5;
	c *= a;
	c /= 100;
	cout << c << endl;
}
