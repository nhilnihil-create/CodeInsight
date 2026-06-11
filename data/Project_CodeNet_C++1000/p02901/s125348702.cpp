#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef   long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define B 998244353ll
#define C 1000000000000000001ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI 3.14159265358979323

ll dp[4096][4096];

int main() 
{
    FAST;
    for(int i=0;i<4096;i++)
    	for(int j=1;j<4096;j++)
    		dp[i][j]=C;
    ll m,n;
    cin>>n>>m;
    ll a,b,c;
    for(int i=0;i<m;i++)
    {
    	cin>>a>>b;
    	ll x=0;
    	for(int j=0;j<b;j++)
    	{
    		cin>>c;
    		x+=powl(2,c-1);
    	}	
    	if(i==0)
    		dp[i][x]=a;
    	else
    	{
    		for(int j=0;j<4096;j++)
	    		if(dp[i-1][j]!=C && (j|x)<4096)
	    			dp[i][j|x]=min(dp[i][j|x],(dp[i-1][j]+a));
	    	for(int j=0;j<4096;j++)
				dp[i][j]=min(dp[i][j],dp[i-1][j]);
    	}
    }
    ll ans=LLONG_MAX;
    c=powl(2,n)-1;
    for(int i=0;i<m;i++)
    	ans=min(ans,dp[i][c]);
    if(ans==C)
    	cout<<-1;
    else
    	cout<<ans;
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}