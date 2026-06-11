#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
vector<int> ind[255];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  int p = 0;
  ll ans = 0;
  for (int i = 0; i < s.length(); i++) {
    ind[s[i] - 'a'].pb(i);
  }
  // for (int i = 0; i < 26; i++) {
  //   cout << i << ' ';
  //   for (int x : ind[i])
  //     cout << x << ' ';
  //   cout << endl;
  // }
  for (int j = 0; j < t.length(); j++) {
    // cout << t[j] - 'a' << endl;
    if (ind[t[j] - 'a'].empty()) {
      cout << -1 << endl;
      return 0;
    } else {
      auto i = lower_bound(ind[t[j] - 'a'].begin(), ind[t[j] - 'a'].end(), p);
      if (i == ind[t[j] - 'a'].end()) {
        ans += (s.length() - p);
        i = ind[t[j] - 'a'].begin();
        ans += (*i + 1);
        p = *i + 1;
      } else {
        ans += (*i - p + 1);
        p = (*i + 1) % s.length();
      }
      // cout << *i << ' ' << ans << endl;
    }
  }
  cout << ans << endl;
}