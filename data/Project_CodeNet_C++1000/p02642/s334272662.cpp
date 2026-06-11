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

int a[1000005], b[1000005], c[1000005];

signed main(void)
{
	int n; cin >> n;
	rep (i, n) cin >> a[i], b[a[i]]++;
	rep (i, n)
	{
		if (c[a[i]] == 2) continue;
		if (b[a[i]] > 1) c[a[i]] = 2;
		for (int j = 2 * a[i]; j <= 1000000; j += a[i])
		{
			if (b[j]) c[j] = 1;
		}
	}
	int ans = 0;
	rep (i, n) if (!c[a[i]]) ans++;
	cout << ans << endl;
}
