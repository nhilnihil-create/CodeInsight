#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  ll n,d; cin >> n >> d;
  ll ans;
  if(n%(d*2+1)==0) cout << n/(d*2+1) << endl;
  else cout << n/(d*2+1)+1 << endl;
  
  return 0;
}