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

int main(){
   fastt;
   
   ll arr[] = { 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
   ll k;
   cin >> k;
   
   cout << arr[k-1] << endl;
 
   return 0;
}
