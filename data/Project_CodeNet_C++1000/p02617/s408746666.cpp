#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   ll n; cin >> n;
   ll ans = (n*n*n+3*n*n+2*n)/6;
   rep(i,n-1){
      ll u, v; cin >> u >> v;
      if (u>v)swap(u,v);
      ans -= u*(n-v+1);
   }
   cout << ans << endl;
}