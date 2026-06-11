#include <bits/stdc++.h>
#include <random>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
#define all(v) v.begin(), v.end()
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>


using namespace std;
const ll maxn=2e3+100,inf=1e9,LOG=23,mod=1e9+7;
int block = 300, timer = 0;
const ld EPS = 1e-7;

#define bt(i) (1 << (i))
#define int ll

int n, dp[maxn][maxn], ans;
pii a[maxn];

main()
{
	cin >> n;
	forn(1, i, n)
	{
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a + 1, a + 1 + n);
	nfor(1, len, n)
	{
		forn(1, l, n - len + 1)
		{
			int r = l + len - 1;
			dp[l+1][r] = max(dp[l][r] + a[r-l+1].f * abs(a[r-l+1].s-l), dp[l+1][r]);
			dp[l][r-1] = max(dp[l][r] + a[r-l+1].f * abs(a[r-l+1].s-r), dp[l][r-1]);
		}
	}
	forn(0, i, n)
	{
		ans = max(ans, dp[i + 1][i]);
	}
	cout << ans;
}