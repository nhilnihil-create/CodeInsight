#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int is_black(vector<string> &S, int i, int j) {
  if (S.at(i).at(j) == '#') {
    return 1;
  }
  return 0;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, W;

  cin >> H >> W;

  vector<string> S(H);
  vector<vector<int>> dp(H, vector<int>(W));

  for (int64_t i = 0; i < H; i++) {
    cin >> S.at(i);
  }
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (i == 0) {
        if (j == 0) {
          dp.at(i).at(j) = is_black(S, i, j);
        } else {
          if (S.at(i).at(j - 1) == S.at(i).at(j)) {
            dp.at(i).at(j) = dp.at(i).at(j - 1);
          } else {
            dp.at(i).at(j) = dp.at(i).at(j - 1) + is_black(S, i, j);
          }
        }
      } else {
        if (j == 0) {
          if (S.at(i - 1).at(j) == S.at(i).at(j)) {
            dp.at(i).at(j) = dp.at(i - 1).at(j);
          } else {
            dp.at(i).at(j) = dp.at(i - 1).at(j) + is_black(S, i, j);
          }
        } else {
          auto tmp_from_left = dp.at(i - 1).at(j);
          if (S.at(i - 1).at(j) == S.at(i).at(j)) {
          } else {
            tmp_from_left += is_black(S, i, j); 
          }
          auto tmp_from_up = dp.at(i).at(j - 1);
          if (S.at(i).at(j - 1) == S.at(i).at(j)) {
          } else {
            tmp_from_up += is_black(S, i, j); 
          }
          if (tmp_from_left > tmp_from_up) {
            dp.at(i).at(j) = tmp_from_up;
          } else {
            dp.at(i).at(j) = tmp_from_left;
          }
        }
      }
    }
  }

  cout << dp.at(H - 1).at(W - 1);

  return 0;
}
