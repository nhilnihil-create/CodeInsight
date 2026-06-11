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
  int Q;
  cin >> Q;
  deque<char> ans(0);
  REP(i, S.size()) ans.push_back(S[i]);
  bool tenti = false;
  REP(i, Q) {
    int id;
    cin >> id;
    if (id == 1) {
      tenti = !tenti;
    } else {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        if (tenti) {
          ans.push_back(c);
        } else {
          ans.push_front(c);
        }
      } else {
        if (!tenti) {
          ans.push_back(c);
        } else {
          ans.push_front(c);
        }
      }
    }
  }
  if (tenti) reverse(ans.begin(), ans.end());
  REP(i, ans.size()) { cout << ans[i]; }
  cout << endl;
}