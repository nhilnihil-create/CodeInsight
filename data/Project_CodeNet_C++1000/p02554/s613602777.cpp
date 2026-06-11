#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
const int mod=1e9+7;
int dp[1000006][2][2];
signed main()
{
	int n;
	cin>>n;
	dp[0][0][0]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				if (dp[i][j][k]){
					int aa=dp[i][j][k];
					if (j+k==0)
						dp[i+1][0][1]+=aa,dp[i+1][1][0]+=aa,dp[i+1][0][0]+=aa*8%mod;
					if (j+k==1)
						dp[i+1][1][1]+=aa,dp[i+1][j][k]+=aa*9%mod;
					if (j&&k)
						dp[i+1][1][1]+=aa*10%mod;
				}
	cout<<dp[n][1][1]%mod;
	re 0;
}
