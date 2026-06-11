#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int mod = 1e9 + 7;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<ll>v(m);
	for (int i = 0; i < m; i++) 	{
		cin >> v[i];
	}
	vector<ll>dp(n + 5, -1);
	for (int i = 0; i < m; i++) {
		dp[v[i]] = 0;
	}
	dp[0] = 1;
	if (dp[1] == -1)dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (dp[i] == 0)continue;
		else
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n] << endl;
}