#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  string s;
  map<string, ll> mp;
  rep(i,0,N-1) {
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }

  ll ans = 0;
  for (auto p : mp) ans += p.second * (p.second - 1) / 2;

  cout << ans << endl;
  return 0;
}
