#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> s(M), c(M);
  REP(i, M) cin >> s[i] >> c[i];
  REP(i, 1000) {
    int a = i;
    string S = to_string(i);
    if (S.size() != N) continue;
    bool t = true;
    REP(j, M) {
      if (s[j] > S.size()) {
        t = false;
        break;
      }
      if (S[s[j] - 1]-'0' != c[j]) {
        t = false;
        break;
      }
    }
    if (!t) continue;
    cout << i << endl;
    return 0;
  }
  cout << -1 << endl;
}