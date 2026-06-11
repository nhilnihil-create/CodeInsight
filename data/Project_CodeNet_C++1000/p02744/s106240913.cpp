/*---------------------------------- NEVER GIVE UP --------------------------------------------*/

/*

Some people think that if their opponent plays a beautiful game, it’s OK to lose. I don’t. You have to be merciless
-- MAGNUS CARLSEN

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define num dp
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug1(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define debug3(x,y,z) cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define fastt ios_base::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL)

const ll modd=1e9+7;
const ll inf=1e18;

ll poww(ll a,ll b){
  ll ans=1;
  while(b){
    if(b&1LL) ans=(ans*a);
    a=(a*a);
    b=b>>1LL;
  }
  return ans;
}

/*    
         -> mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
         -> cout<<"Case #"<<casee<<": "<<ans<<endl; 

*/

/*-----------------------------------------------------------------------------------------------*/

vector <vector<ll>> dp[11][11];
vector <string> ans;

int main(){
   fastt;
   
   ll n;
   
   cin >> n;
   
   for(ll i = 1; i <= n; i++)
      for(ll j = 1; j <= n; j++){
		  if(i == 1 && j == 1){
			  vector <ll> vec;
			  vec.pb((1ll << (n-i)));
			  dp[i][j].pb(vec);
		  }
		  for(auto k : dp[i-1][j-1]){
			  k.pb((1ll << (n-i)));
			  dp[i][j].pb(k);
		  }
		  for(auto k : dp[i-1][j]){
			  for(ll l = 0; l < j; l++){
				  ll cpy = k[l];
				  k[l] |= (1LL << (n-i));
				  dp[i][j].pb(k);
				  k[l] = cpy; 
			  }
		  }
	  }
	  
   string ss = "";
   
   for(ll i = 1; i <= n; i++){
	   ss += "a";
   }  
	  
   for(ll i = 1; i <= n; i++){
	   for(ll j = 0; j < (ll)dp[n][i].size(); j++){
		   sort(num[n][i][j].begin() , num[n][i][j].end() , greater <ll>());
		   ll ind = 0;
		   for(auto k : num[n][i][j]){
			   for(ll l = 0; l < n; l++){
				   if(k & (1LL << l)) ss[n-1-l] = ('a'+ind);
			   }
			   ind++;
		   }
		   ans.pb(ss);
	   }
   }

   sort(ans.begin(),ans.end());
   
   for(auto j : ans) cout << j << '\n';
 
   return 0;
}



