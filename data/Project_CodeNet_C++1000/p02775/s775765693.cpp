#include <bits/stdc++.h>
using namespace std;
#define long long long
#define read cin >>
#define echo cout <<
#define fin << endl
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)

// for debug macro
bool global_debug_flag = false;
#define DEBUG(val) \
  if (global_debug_flag) cout << #val << " = " << val << endl

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector<vector<int>> data(2, vector<int>(s.length() + 1));
  int x = s[0] - '0';
  data[0][0] = x;
  data[1][0] = 10 - x;
  FOR(i, 0, s.length() - 1) {
    int now = s[i + 1] - '0';
    data[0][i + 1] = min(data[0][i] + now, data[1][i] + now + 1);
    data[1][i + 1] = min(data[0][i] + 10 - now, data[1][i] + 10 - (now + 1));
  }

  REP(j, s.length()) {
    REP(i, 2) {
      DEBUG(i);
      DEBUG(j);
      DEBUG(data[i][j]);
    }
  }
  cout << min(data[0][s.length() - 1], data[1][s.length() - 1] + 1) << endl;
}
