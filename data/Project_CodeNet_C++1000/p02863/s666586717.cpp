#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
int main() {
  int N, T;
  cin >> N >> T;
  vector<PI> A(N + 1);
  rrep(i, N) {
    cin >> A.at(i).first;
    cin >> A.at(i).second;
  }
  sort(A.begin(), A.end());
  VVI dp(N + 1, VI(T)); // dp.at(i) //the number of selected goods=i;
  rrep(i, N) {
    rep(j, min(A.at(i).first, T)) { dp.at(i).at(j) = dp.at(i - 1).at(j); }
    for (int j = A.at(i).first; j < T; j++) {
      dp.at(i).at(j) = max(dp.at(i - 1).at(j),
                           dp.at(i - 1).at(j - A.at(i).first) + A.at(i).second);
    }
  }
  int maxsat = 0;
  rrep(i, N - 1) {
    maxsat = max(maxsat, dp.at(i).at(T - 1) + A.at(i + 1).second);
  }
  cout << maxsat << endl;
  return 0;
}
