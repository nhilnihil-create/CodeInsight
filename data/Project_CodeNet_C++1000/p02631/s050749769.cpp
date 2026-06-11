#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef unsigned long long ull;

const int MOD =  1000000007; //   1000000009 , 1000000023 ,1000000007 , 998244353
const ll INF = ll(1e18);
const ld PI = 4*atan((ld)1);

using namespace __gnu_pbds;
template<typename T, class cmp = std::less<T>>
using Tree = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
  
#ifdef AVI  
  freopen("input.txt" , "r" , stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  
  ll tt = 1 , cc = 1;
  //cin >> tt;
  while(tt--){
    ll n;
    cin >> n;
    vector<ll>ar(n);
    ll x = 0;
    for(auto &y:ar)cin >> y , x ^= y;
    for(auto &y:ar){
      cout << (y^x) << ' ';
    }
  }
  

}