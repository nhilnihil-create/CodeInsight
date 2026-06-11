#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<ll> divisor(ll n) {
  vector<ll> f(n+1);
  for (ll i = 2; i <= n; i++) f[i] = 2*i;
  f[1] = 1;
  for (ll i = 2; i <= (n+1)/2; i++) {
    for (ll j = i * 2; j <= n; j += i) {
      f[j] += j;
    }
  }
  return f;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> f = divisor(N);

  ll ans = 0;
  for (ll i = 1; i <= N; i++) {
    ans += f[i];
  }
  cout << ans << endl;
  return 0;
}
