#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  string S;
  cin >> S;

  ll ans = 0;
  vector<int> v(S.length()+1, 0);
  rep(i, S.length()) {
    if (S[i] == '<') {
      v[i + 1] = v[i] + 1;
    }
  }
  for (int i = S.length() - 1; i >= 0; --i) {
    if (S[i] =='>') {
      if (v[i] <= v[i + 1]) {
        v[i] = v[i + 1] + 1;
      }
    }
  }

  rep(i, v.size()) {
    ans += v[i];
  }

  cout << ans << endl;
  
  return 0;
}