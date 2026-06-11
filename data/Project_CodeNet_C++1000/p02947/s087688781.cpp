#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n;
  cin >> n;
  ll ans = 0;
  vector<string> s(n);
  rep(i,n) {
    string t; cin >> t;
    sort(t.begin(), t.end());
    s[i] = t;
  }
  sort(s.begin(), s.end());
  ll cnt = 1;
  rep(i,n-1) {
    if (s[i] == s[i+1]) cnt++;
    else {
      ans += (cnt*(cnt-1)/2);
      cnt = 1;
    } 
  }
  ans += cnt*(cnt-1)/2;
  cout << ans << endl;

  return 0;
}