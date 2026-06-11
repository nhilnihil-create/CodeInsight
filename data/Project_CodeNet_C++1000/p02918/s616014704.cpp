#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ans = 0;
  rep(i, s.size()) {
    if (i == 0 && s[i] == 'L') continue;
    if (i == s.size()-1 && s[i] == 'R') continue;
    if (s[i] == 'L' && s[i-1] == 'L') ++ans;
    if (s[i] == 'R' && s[i+1] == 'R') ++ans;
  }
  int seq = 1;
  rep(i, s.size()-1) {
    if (s[i+1] != s[i]) ++seq;
  }
  if (k < seq / 2) ans += 2 * k;
  else ans = n-1;
  cout << ans << endl; 
  return 0;
}