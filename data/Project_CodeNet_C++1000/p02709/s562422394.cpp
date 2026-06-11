#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
const int N = 2005;
ll M = 1e9 + 7;
ll power(ll x,ll y){ ll res=1; while(y){ if(y&1) res=(res*x)%M; y=y>>1; x=(x*x)%M;} }
ll dp[N][N];

int main() {
	// your code goes here
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	int n; cin>>n;
	vector < pair <ll,ll> > v(n);
	for(int i=1;i<=n;i++)
	{
	    cin>>v[i-1].ff; v[i-1].ss = i;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	ll ans = -1;
	for(int i=0;i<=n;i++)
	{
	    for(int j=0;j<=n;j++)
	    {
	        if( i+j == n )
	        {
	            ans = max(ans,dp[i][j]);
	            break;
	        }
	        dp[i+1][j] = max(dp[i+1][j],dp[i][j]+abs(v[i+j].ss-i-1)*v[i+j].ff);
	        dp[i][j+1] = max(dp[i][j+1],dp[i][j]+abs(v[i+j].ss-n+j)*v[i+j].ff);
	    }
	}
	cout<<ans;
	
	return 0;
}
