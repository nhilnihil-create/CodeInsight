#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  string s; ll k;
  cin >> s >> k;
  ll n = s.size();
  ll ans = 0;
  int cnt = 1;
  rep(i,n-1) {
    if (s[i] == s[i+1]) cnt++;
    else break;
  }
  if (cnt == n) {
    ans = n*k/2;
    cout << ans << endl;
    return 0;
  }else {
    rep(i,n-1) {
      if (s[i] == s[i+1]) {ans++; s[i+1] = '#';}
    }
    ans *= k;
    if (s[0] == s[n-1] && cnt % 2 == 1) ans += k-1;
  }
  cout << ans << endl;
  return 0;
}