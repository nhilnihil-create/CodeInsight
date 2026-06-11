#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  int n;
  cin >> n;
  ll k;
  cin >> k;
  vector<ll> a(n), f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(f.begin(), f.end(), greater<ll>());
  sort(a.begin(), a.end());

  auto ok = [&](ll m){
    ll cnt = 0;
    for (int i = 0; i < n; i++) cnt += max(0LL, a[i] - m / f[i]);
    return cnt <= k;
  };
  ll l = -1, r = 1e12;

  while (r - l > 1) {
    ll m = (r + l) / 2;
    if (ok(m)) r = m;
    else l = m;
  }
  cout << r << endl;
  return 0;
}