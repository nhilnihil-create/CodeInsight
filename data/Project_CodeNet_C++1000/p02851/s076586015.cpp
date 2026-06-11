#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int mod(int val, int m) {
  int res = val % m;
  if (res < 0) res += m;
  return res;
}

int main() {
  int n; ll k;
  cin >> n >> k;
  vector<ll> s(n+1);
  s[0] = 0;
  rep(i,1,n+1) {
    int a;
    cin >> a;
    s[i] = (a + s[i-1]) % k;
  }
  map<int,ll> m;
  ll ans = 0;
  vector<int> p(n+1);
  rep(i,0,n+1) {
    p[i] = mod(s[i] - i, k);
    ans += m[p[i]];
    m[p[i]]++;
    if (i+1 >= k) {
      m[p[i-k+1]]--;
    }
  }
  cout << ans << endl;
  return 0;
}
