#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

vector<int> calc(const string &S, char c) {
  vector<int> v(S.size() + 1, 0);
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == c) {
      v[i + 1] = v[i] + 1;
    }
  }

  return v;
}

void solve() {
  string S;
  cin >> S;

  auto v = calc(S, '<');

  reverse(S.begin(), S.end());
  auto w = calc(S, '>');
  reverse(w.begin(), w.end());

  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    ans += max(v[i], w[i]);
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
