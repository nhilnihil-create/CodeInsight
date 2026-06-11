#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e3 + 5;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
int cache[N][N];

int dp(int i, int j)
{
	if(i > n)
		return 0;
	if(j > m)
		return 0;
	int &ans = cache[i][j];
	if(ans != -1)
		return ans;
	if(a[i] == b[j])
		ans = 1 + dp(i + 1, j) + dp(i, j + 1);
	else
		ans = dp(i + 1, j) + dp(i, j + 1) - dp(i + 1, j + 1);
	ans += MOD;
	ans %= MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	int ans = dp(1, 1);
	ans++;
	ans %= MOD;
	cout << ans;
	return 0;
}
