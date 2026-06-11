#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

struct rlcnt {
  ll id;
  ll rcnt;
  ll lcnt;
};

int main() {
  string s;
  cin >> s;
  vector<rlcnt> d;
  ll rc = 0;
  ll lc = 0;
  bool rl = true;  // true r false l
  rep(i, s.size() - 1) {
    if (s[i] == 'R' && rl) rc++;
    if (s[i] == 'L' && rl) rl = false;
    if (s[i] == 'R' && !rl) {
      rl = true;
      rc = 1;
    }
    if (s[i] == 'R' && s[i + 1] == 'L') {
      rlcnt tmp;
      tmp.id = i;
      tmp.rcnt = rc - 1;
      d.push_back(tmp);
    }
  }
  ll index = 0;
  rep(i, s.size() - 1) {
    if (s[i] == 'L' && s[i + 1] == 'R') {
      d[index].lcnt = i - d[index].id - 1;
      index++;
    }
  }
  d[d.size() - 1].lcnt = s.size() - 1 - d[d.size() - 1].id - 1;

  vector<ll> ans(s.size());
  index = 0;
  rep(i, s.size()) {
    if (i == d[index].id) {
      ans[i] = d[index].rcnt / 2 + d[index].lcnt / 2 + (d[index].lcnt % 2) + 1;
      ans[i + 1] =
          d[index].lcnt / 2 + d[index].rcnt / 2 + (d[index].rcnt % 2) + 1;
      index++;
    }
  }
  // rep(i, d.size()) cout << "(" << d[i].id << ", " << d[i].rcnt << ", "
  //                        << d[i].lcnt << ")"
  //                       << ", ";
  // cout << endl;

  // rep(i, s.size()) cout << ans[i] << ", ";
  // cout << endl;
  rep(i, s.size()) cout << ans[i] << endl;
  return 0;
}
