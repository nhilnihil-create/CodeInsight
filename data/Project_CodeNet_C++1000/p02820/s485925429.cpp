#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  int n, k;
  cin >> n >> k;
  vector<P> d(3);
  rep(i,3) cin >> d[i].first, d[i].second = i;
  string s;
  cin >> s;
  map<char, int> id;
  id['r'] = 2;
  id['s'] = 0;
  id['p'] = 1;

  sort(d.begin(), d.end(), greater<P>());
  vector<int> ok(n, 1);
  int res = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      if (ok[j]) {
        if (d[i].second == id[s[j]]) {
          if (j - k >= 0 && s[j - k] == s[j] && !ok[j - k]) continue;
          res += d[i].first;
          ok[j] = 0;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
} 