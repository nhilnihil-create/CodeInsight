#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAX_N = 3005;
int N, S;
int A[MAX_N];

ll dp[MAX_N][MAX_N]; // len, sum

ll powmod(ll x, int y)
{
	ll res = 1;
	while(y){
		if(y&1) (res*=x)%=MOD;
		(x*=x)%=MOD;
		y>>=1;
	}
	return res;
}

void solve()
{
	dp[0][0]=powmod(2,N);
	for(int i=0;i<N;++i)for(int j=0;j<=S;++j){
		(dp[i+1][j]+=dp[i][j])%=MOD;
		if(j+A[i]<=S) (dp[i+1][j+A[i]]+=dp[i][j]*powmod(2,MOD-2)%MOD)%=MOD;
	}
	cout<<dp[N][S];
}

int main()
{
	cin >> N >> S;
	for(int i=0;i<N;++i) cin >> A[i];
	solve();
	return 0;
}