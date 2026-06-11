#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAX_N = 2006;
int N, M;
int a[MAX_N];
int b[MAX_N];

ll dp[MAX_N][MAX_N];

void solve()
{
	for(int i=1;i<=N;++i)for(int j=1;j<=M;++j){
		(dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+MOD)%=MOD;
		if(a[i-1]==b[j-1]) (dp[i][j]+=1+dp[i-1][j-1])%=MOD;
	}
	cout << (dp[N][M]+1)%MOD;
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;++i) cin >> a[i];
	for(int i=0;i<M;++i) cin >> b[i];
	solve();
	return 0;
}