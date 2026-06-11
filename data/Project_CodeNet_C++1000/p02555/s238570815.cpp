#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+4;
const int MOD = 1e9+7;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int s;
	cin>>s;
	int dp[s+1]={0};
	dp[0]=1;
	for(int i=1;i<=s;i++)
	{
		for(int j=i;j>=3;j--)
		{
			dp[i]+=dp[i-j];
			dp[i]%=MOD;
		}
	}
	cout<<dp[s]<<"\n";
} 

// nc1*(n-1)c1*9^(n-2)

