#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
vector<P> enum_divisors(long long N) {
    vector<P> res;
    for (long long i = 1; i * i <= N; ++i) {
      if (N % i == 0)
        res.push_back( pair(i, N/i) );
    }
    return res;
}

int main() {
  ll n; cin >> n;
  vector<P> p = enum_divisors(n);
  ll k = n+1;
  ll ans = k;
  
  rep(i, p.size()){
    if(k > p[i].first + p[i].second - 2)
      ans = p[i].first + p[i].second - 2;
  }
  
  cout << ans << endl;
}