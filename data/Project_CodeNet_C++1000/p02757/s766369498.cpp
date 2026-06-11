#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (2e9)

int main() {
  ll ans = 0;
  ll n, p; cin >> n >> p;
  string s; cin >> s;

  if(10 % p == 0) {
    for(int i = s.length() - 1; i >= 0; i--) {
      if((s[i]-'0') % p == 0) ans += i + 1;
    }
    cout << ans << endl;
    return 0;
  }

  vector<ll> sum(n+1);
  ll ten = 1;
  for(int i = n - 1; i >= 0; i--) {
    ll a = (s[i]-'0') * ten % p;
    sum[i] = (sum[i+1] + a) % p;
    ten *= 10; ten %= p;
  }
  vector<ll> cnt(p);
  for(int i = n; i >= 0; i--) {
   cnt[sum[i]]++;
  }
  for(auto i = cnt.begin(); i != cnt.end(); i++) {
    ans += *i * (*i - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}