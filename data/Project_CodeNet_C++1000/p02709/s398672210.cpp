#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fi first
#define se second
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e3 + 5;
const ll LINF = 1e18 + 5;
constexpr int mod = 1e9 + 7;
int n, a[N];
ll dp[N][N];
pii b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) 
	{
		cin >> a[i];
		b[i] = {a[i], i};
	}
	sort(b+1, b+n+1); reverse(b+1, b+n+1);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for(int i=1; i<=n; i++)
		for(int j=0; j<i; j++)
		{
			if(dp[i-1][j]==-1) continue;
			dp[i][j] = max(dp[i][j], dp[i-1][j]+1ll*b[i].fi*abs(b[i].se-(n-(i-1-j))));
			dp[i][j+1] = max(dp[i][j+1], dp[i-1][j]+1ll*b[i].fi*abs(b[i].se-(j+1)));
		}
	ll ans = *max_element(dp[n], dp[n]+n+1);
	printf("%lld\n", ans);
	return 0;
}