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
	int n; cin >> n;
	int a[n], b[n];
	rep (i, n) cin >> a[i] >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	double ac, bc;
	if (n % 2) ac = a[(n+1)/2-1], bc = b[(n+1)/2-1];
	else ac = (a[n/2-1]+a[n/2]) / 2.0, bc = (b[n/2-1]+b[n/2]) / 2.0;
	int ans;
	if (n % 2) ans = bc - ac + 1;
	else ans = (bc - ac) * 2 + 1;
	cout << ans << endl;
}

