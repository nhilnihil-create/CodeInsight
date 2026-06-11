#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  rep(i,n) {
    if (s[i] == 'R') a[i] = 0;
    if (s[i] == 'G') a[i] = 1;
    if (s[i] == 'B') a[i] = 2;
  }
  vector<ll> cnt(3);
  rep(i,n) cnt[a[i]]++;
  ll ans = 1;
  rep(i,3) ans *= cnt[i];
  rep(j,n)rep(i,j) {
    int k = j + (j-i);
    if (k < n) {
      if (s[i] == s[j]) continue;
      if (s[i] == s[k]) continue;
      if (s[k] == s[j]) continue;
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
