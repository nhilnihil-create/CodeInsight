#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(){
  ll n; cin >> n;
  ll ans = 0;
  const auto &res = prime_factorize(n);
  for(auto p: res){
    ll e = p.second;
    ll tmp = 0, cur = 1;
    while(e >= cur) e -= cur++, ++tmp;
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
