
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> data(n);
  REP(i, n) {
    int a;
    cin >> a;
    vector<pair<int, int>> vi;
    REP(j, a) {
      int x, y;
      cin >> x >> y;
      vi.push_back(make_pair(x - 1, y));
    }
    data[i] = vi;
  }
  /*
  REP(i, n) {
    for (auto e : data[i]) {
      cout << e.first << " " << e.second << endl;
    }
  }*/
  int ans = 0;
  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> now_honest;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        now_honest.push_back(i);
      }
    }

    bool judge = true;
    for (auto x : now_honest) {
      for (auto statement : data[x]) {
        bool a = statement.second == 1 &&
                 (find(ALL(now_honest), statement.first)) == now_honest.end();
        bool b = statement.second == 0 &&
                 (find(ALL(now_honest), statement.first)) != now_honest.end();
        if (a || b) {
          judge = false;
        }
      }
    }

    if (judge) {
      int len = now_honest.size();
      ans = max(ans, len);
    }
  }
  cout << ans << endl;
}