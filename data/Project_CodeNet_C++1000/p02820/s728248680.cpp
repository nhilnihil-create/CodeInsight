#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  map<char, int> mp;
  int r, s, p;
  cin >> r >> s >> p;
  mp['r'] = p;
  mp['s'] = r;
  mp['p'] = s;
  string t;
  cin >> t;
  vector<int> vec(n);
  rep(i,n) {
    vec[i] = mp[t[i]];
    // cout << vec[i] << endl;
    if(i >= k) {
      if(t[i] == t[i-k]) {
        vec[i] = 0;
        t[i] = 'x';
      }
    }
  }
  int ans = 0;
  rep(i,n) ans += vec[i];
  cout << ans << endl;
  return 0;
}
