#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

int main() {
	int n; cin >> n;
    ll ans = 0;
    ll high = 0;
  rep(i, n){
    ll a; cin >> a;
    ans += max(high - a, ll(0));
    high = max(a, high);
  }
  
  cout << ans << endl;
   return 0;
}
