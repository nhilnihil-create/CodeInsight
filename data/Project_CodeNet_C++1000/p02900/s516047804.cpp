#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (a%b == 0) {
    return(b);
  } else {
    return(gcd(b, a%b));
  }
}

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

int main() {
  ll a,b;
  cin >> a >> b;
  ll k = gcd(a,b);
  vector<pair<ll,ll>> ans = prime_factorize(k);
  cout << ans.size() + 1 << endl;
  return 0;
}
