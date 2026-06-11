#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
ll P[100005];
const ll mod = 998244353;

ll pow(ll x, ll y) {
    if (y == 0LL) return 1LL;
    ll X = 1LL;
    for (ll i = 0LL; i < y; i++) {
      X *= x;
      X %= mod;
    }
    return X;
}

int main() {
  ll N;
  cin >> N;
  bool can = true;
  ll M = 0LL;
  for(ll i = 0; i < N; i++) {
    ll x;
    cin >> x;
    chmax(M, x);
    if(i == 0LL && x != 0) {
      can = false;
      break;
    }
    P[x]++;
  }
  if(P[0] != 1) can = false;
  ll ans = 1LL;
  for(ll i = 1LL; i <= M; i++) {
    ans *= pow(P[i-1], P[i]);
    ans %= mod;
  }
  if(can) cout << ans << endl;
  if(!can) cout << 0 << endl;
}
  