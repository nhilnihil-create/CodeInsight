#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  vector<vector<int> > as(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> as[i][j];
  int n;
  cin >> n;
  vector<int> bs(n);
  rep(i, n) cin >> bs[i];
  bool ok = false;
  rep(i, 3) {
    int cnt = 0;
    rep(j, n) {
      if (bs[j] == as[i][0]) {
        cnt++;
      }
      if (bs[j] == as[i][1]) {
        cnt++;
      }
      if (bs[j] == as[i][2]) {
        cnt++;
      }
    }
    if (cnt == 3) {
      cout << "Yes" << endl;
      return 0;
    }
    cnt = 0;
    rep(j, n) {
      if (bs[j] == as[0][i]) {
        cnt++;
      }
      if (bs[j] == as[1][i]) {
        cnt++;
      }
      if (bs[j] == as[2][i]) {
        cnt++;
      }
    }
    if (cnt == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  int cnt = 0;
  rep(i, n) {
    if (bs[i] == as[0][0]) {
      cnt++;
    }
    if (bs[i] == as[1][1]) {
      cnt++;
    }
    if (bs[i] == as[2][2]) {
      cnt++;
    }
    if (cnt == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cnt = 0;
  rep(i, n) {
    if (bs[i] == as[2][0]) {
      cnt++;
    }
    if (bs[i] == as[1][1]) {
      cnt++;
    }
    if (bs[i] == as[0][2]) {
      cnt++;
    }
    if (cnt == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
