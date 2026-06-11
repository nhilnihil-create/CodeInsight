#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pie 3.1415926536
#define pb push_back
#define N 1000000007
#define M 998244353
#define ff first
#define ss second
#define INF 1ll<<63 - 1
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define nrep(i,a,b) for(int i=a;i>=b;i--)
#define pl pair<ll,ll>
#define pi pair<int,int>
#define pll pair<pair<ll,ll>, ll> 
#define pii pair< int, pair<int,int> >
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t,x=0,b,y,q,z,k,n,m;
    cin>>n>>k;
    ll r,s,p;
    cin>>r>>s>>p;
    string str;
    cin>>str;
    ll dp[n+5][3];
    memset(dp,0,sizeof(dp));
    ll ans = 0;
    rep(i,0,k-1){
    	if(str[i] == 's'){
    		dp[i][0] = r;
		}else{
			dp[i][0] = 0;
		}
		if(str[i] == 'p'){
    		dp[i][1] = s;
		}else{
			dp[i][1] = 0;
		}
		if(str[i] == 'r'){
    		dp[i][2] = p;
		}else{
			dp[i][2] = 0;
		}
		if(i + k >= n){
			ans += max(dp[i][0],max(dp[i][1],dp[i][2]));
			continue;
		}
		ll val = 0;
		for(ll j = i+k;j<n;j+=k){
			if(str[j] == 's'){
    			dp[j][0] = r;
    			dp[j][0] += max(dp[j-k][1],dp[j-k][2]);
			}else{
				dp[j][0] = 0;
				dp[j][0] += max(dp[j-k][1],dp[j-k][2]);
			}
			if(str[j] == 'p'){
	    		dp[j][1] = s;
	    		dp[j][1] += max(dp[j-k][0],dp[j-k][2]);
			}else{
				dp[j][1] = 0;
				dp[j][1] += max(dp[j-k][0],dp[j-k][2]);
			}
			if(str[j] == 'r'){
	    		dp[j][2] = p;
	    		dp[j][2] += max(dp[j-k][1],dp[j-k][0]);
			}else{
				dp[j][2] = 0;
				dp[j][2] += max(dp[j-k][1],dp[j-k][0]);
			}
			val = max(val,max(dp[j][0],max(dp[j][1],dp[j][2])));
		}
		ans +=val;
	}
	cout<<ans;
}
