#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;

 

 
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
 

 

 

 

int main()
{
    ios_base::sync_with_stdio(false); // don't use printf and scanf
    cin.tie(NULL); // cout<<fixed<<setprecision
    
	ll s;cin>>s;
	ll dp[s+1];
	for(ll i=1;i<=s;i++) dp[i]=1;
	dp[0]=0;dp[1]=0;dp[2]=0;dp[3]=1;
	for(ll i=4;i<=s;i++)
	{
		ll ans=1ll;
		for(ll j=3;j<=i-3;j++)
		{
			ans+=dp[j];ans%=INF;
		}
		dp[i]=ans;
	}
	cout<<dp[s]<<'\n';
	return 0;
}


