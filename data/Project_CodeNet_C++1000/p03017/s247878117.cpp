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
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D, A--, B--, C--, D--;
  string S;
  cin >> S;
  for (int i = A; i <= max(C, D); i++) {
    if (S[i] == '#' && S[i + 1] == '#') {
      cout << "No" << endl;
      return 0;
    }
  }
  if (D < C) {
    bool t = false;
    for (int i = B - 1; i <= D - 1; i++) {
      if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') t = true;
    }
    if (t) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  } else {
    cout << "Yes" << endl;
  }
}