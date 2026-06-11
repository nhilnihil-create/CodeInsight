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
	int x, y;
	cin >> x >> y;
	if (y % 2) {cout << "No" << endl; return 0;}
	y /= 2;
	int a, b;
	b = y - x;
	a = x - b;
	if (a < 0 || b < 0) {cout << "No" << endl; return 0;}
	if (a + 2*b != y) {cout << "No" << endl; return 0;}
	cout << "Yes" << endl;
}
