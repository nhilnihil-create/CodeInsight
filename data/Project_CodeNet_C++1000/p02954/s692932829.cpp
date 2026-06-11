#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  int64_t n = S.size();
  vector<int64_t> sol(n, 0);

  int64_t mv = 0;
  vector<int64_t> mvs(n, 0);
  for (int64_t i = n - 1; i > -1; i--) {
    if (S.at(i) == 'R') {
      mv++;
      mvs.at(i) = mv;
    } else {
      mv = 0;
    }
  }

  mv = 0;
  for (int64_t i = 0; i < n; i++) {
    if (S.at(i) == 'L') {
      mv--;
      mvs.at(i) = mv;
    } else {
      mv = 0;
    }
  }

  for (int64_t i = 0; i < n; i++) {
    sol.at(i + mvs.at(i) - (abs(mvs.at(i)) / mvs.at(i)) * (abs(mvs.at(i)) % 2))++;
  }

  for (int64_t i = 0; i < n; i++) {
    cout << sol.at(i) << " ";
  }

  return 0;
}
