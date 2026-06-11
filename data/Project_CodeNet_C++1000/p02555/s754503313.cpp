#include <bits/stdc++.h>
using namespace std;
#define w(x) int x;cin>>x;while(x--)
#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define vi vector<int>
#define fr(a,b) for(int i=a;i<=b;i++)
#define inf 1e18
#define mod 1000000007
int main()
{   
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
#endif*/
	fast;
    ll n;
    cin>>n;
    ll dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
    	ll sum=0;
    	for(int j=0;j<=i;j++)
    	{
    		if((i-j)>=3)
    			sum=(sum%mod+dp[j]%mod)%mod;
    	}
    	dp[i]=sum;
    }
    cout<<dp[n]<<"\n";
	return 0;
}