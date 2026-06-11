#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  string S;
  cin >> S;
  vector<int> ans(S.size() + 1);
  vector<int> kyori(S.size(), -1);
  int cnt = -1;
  REP(i, S.size()) {
    if (S[i] == 'L') {
      cnt++;
      kyori[i] = cnt;
    } else {
      cnt = -1;
    }
  }
  REP(i, S.size()) {
    int j = S.size() - 1 - i;
    if (S[j] == 'L') {
      cnt = -1;
    } else {
      cnt++;
      kyori[j] = cnt;
    }
  }
  REP(i, S.size()) {
    if (S[i] == 'L') {
      if (kyori[i] % 2 == 0) {
        ans[i - kyori[i]+1]++;
      } else {
        ans[i - kyori[i]]++;
      }

    } else {
      if (kyori[i] % 2 == 0) {
        ans[i + kyori[i]+1]++;
      } else {
        ans[i + kyori[i] + 2]++;
      }
    }
  }
  REP(i, S.size()) { cout << ans[i + 1] << " "; }
  cout << endl;
}