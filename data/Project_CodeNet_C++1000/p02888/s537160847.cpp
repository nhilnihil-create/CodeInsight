#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
#define repr(i, n) for(ll i = n-1; i >= 0; i--)
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> l(n);
  rep(i, n) cin >> l[i];
  sort(l.begin(), l.end());
  ll ans = 0;
  repr(i, n)repr(j, i){
    auto itr = lower_bound(l.begin(), l.end(), l[i] + l[j]);
    ll ng = distance(itr, l.end());
    ans += (n - 1 - i) - ng;
  }
  
  cout << ans << endl;
  
  return 0;
}