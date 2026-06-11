#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

#define over 1000000000000000000

signed main(void)
{
	int n, a[100005]; cin >> n;
	rep (i, n) cin >> a[i];
	int ans = 1;
	rep (i, n) {if (a[i] == 0) {cout << 0 << endl; return 0;}}
	rep (i, n) {if (ans > over / a[i] + 1 || ans * a[i] > over) {cout << -1 << endl; return 0;} ans *= a[i];}
	cout << ans << endl;
}
