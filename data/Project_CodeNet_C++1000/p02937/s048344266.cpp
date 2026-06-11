#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15)

  string s, t;
  cin >> s >> t;
  vector<vector<ll>> alphabets(26);
  for(int i = 0; i < s.size(); i++) alphabets[s[i]-'a'].emplace_back(i);
  ll index = -1, ans = 0;
  for (int i = 0; i < t.size(); i++) {
    int c = t[i] - 'a';
    if (alphabets[c].empty()) {
      cout << -1 << endl;
      return 0;
    }
    auto it = upper_bound(alphabets[c].begin(), alphabets[c].end(), index);
    if (it == alphabets[c].end()) {
      ans += (ll)(s.size()) - index;
      index = alphabets[c][0];
      ans += index;
    }
    else {
      ans += *it - index;
      index = *it;
    }
  }
  cout << ans << endl;
}
