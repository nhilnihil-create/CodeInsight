#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

signed main(void)
{
	int x, n, p[105] = {0}, tmp;
	cin >> x >> n;
	rep (i, n) cin >> tmp, p[tmp] = 1;
	if (p[x] == 0) {cout << x << endl; return 0;}
	reps (i, 1, inf)
	{
		if (x - i < 0) {cout << x - i << endl; return 0;}
		if (p[x - i] == 0) {cout << x - i << endl; return 0;}
		if (p[x + i] == 0) {cout << x + i << endl; return 0;}
	}
}
