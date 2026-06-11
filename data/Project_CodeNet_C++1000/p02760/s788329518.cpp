#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  vector<vector<int> > as(3, vector<int>(3));
  vector<vector<bool> > op(3, vector<bool>(3, false));
  rep(i, 3) rep(j, 3) { cin >> as[i][j]; }

  int n;
  cin >> n;
  rep(i, n) {
    int b;
    cin >> b;
    rep(j, 3) rep(k, 3) {
      if (as[j][k] == b) {
        op[j][k] = true;
      }
    }
  }
  rep(i, 3) {
    if (op[i][0] && op[i][1] && op[i][2]) {
      cout << "Yes" << endl;
      return 0;
    }
    if (op[0][i] && op[1][i] && op[2][i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if (op[0][0] && op[1][1] && op[2][2]) {
    cout << "Yes" << endl;
    return 0;
  }
  if (op[2][0] && op[1][1] && op[0][2]) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}
