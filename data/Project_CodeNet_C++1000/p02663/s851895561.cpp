#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
        
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
        
#define print(a) {for(auto xxxxx : (a)) cout << xxxxx << ' '; cout << '\n';}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

ll next(){ll x; cin >> x; return x;}
const int maxn = 3e5 + 5, intf = 2e9;
const ll inf = 1e18, mod = 998244353;
const ld eps = 1e-9;



void solve(){
  ll t1 = next()*60;
  t1 += next();
  ll t2 = next()*60;
  t2 += next();

  int k; cin >> k;
  cout << t2 - t1 - k << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cout.precision(20);
  
  for (int t = 1; t--;) {
    solve();
  }
        
  return 0;
}
/*

*/
