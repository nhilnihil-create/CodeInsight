#include <bits/stdc++.h>
using namespace std;

const int N = 2e3;
const int mod = 1e9+7;
int dp[N+100][N+100];
int s[N+10],t[N+10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> s[i];
	for(int i=1;i<=m;i++)cin >> t[i];
	int ans = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = ((dp[i-1][j]+dp[i][j-1])%mod-dp[i-1][j-1]+mod)%mod;
			if(s[i]==t[j]){
				ans = (ans+dp[i-1][j-1]+1)%mod;
				dp[i][j] = (dp[i][j]+dp[i-1][j-1]+1)%mod;
			}
		}
	}
	cout << ans << "\n";
}
