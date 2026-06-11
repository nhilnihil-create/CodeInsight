#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
 
#define sec second
#define fir first
#define mo  998244353
#define inf 1e18
#define rep(i, s, n) for (ll i = s; i < n; i = i + 1)
#define rrep(i,s,n) for(ll i=s;i>=n;i--)
#define adiii\                               
  ios_base::sync_with_stdio(false);\                                      
  cin.tie(NULL);\
  cout.tie(NULL);									
 
ll mod(ll n) { return (n % (ll)mo + (ll)mo)%(ll)mo;}
ll gcd(ll a,ll b) {if (b == 0) return a;return gcd(b, a % b);}

int main(){
	adiii
	ll n;cin>>n;
	using p = pair<ll,ll>;
	vector <p> a;
	rep(i,1,n+1) {ll x;cin>>x;a.pb({x,i});}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	ll dp[n+5][n+5];
	memset(dp,0,sizeof(dp));
	ll ans = 0;
	rep(x,0,n+1){
		rep(y,0,n-x+1){
			
			//if(x+y+1<=n){
				ll nxt_val = a[x+y].first;
				ll nxt_idx = a[x+y].second;
				dp[x+1][y] = max(dp[x+1][y],dp[x][y] + nxt_val*(nxt_idx) - nxt_val*(x+1));
				dp[x][y+1] = max(dp[x][y+1],dp[x][y] - nxt_val*(nxt_idx) + nxt_val*(n - (y)));
				//cout<<x<<" "<<y<<" "<<dp[x+1][y]<<" "<<dp[x][y+1]<<endl;
				ans = max(ans,dp[x+1][y]);
				ans = max(ans,dp[x][y+1]);
				
			//} 
			//ans = max(ans,dp[x][y]);
		
		}
	}
	
	
    cout<<ans<<endl;
    
}
