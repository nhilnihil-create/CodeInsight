#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int K;
  cin >> K;

  vector<vector<vector<int64_t>>> lunlun(19, vector<vector<int64_t>>(10));

  int cnt = 0;
  for (int p = 1; p <= 9; p++) {
    int64_t result = p;
    cnt++;
    if (cnt == K) {
      cout << result << endl;
      return 0;
    }
    lunlun[0][p].push_back(result);
  }

  int64_t shift = 1;
  for (int d = 1; d <= 18; d++) {
    shift *= 10;
    for (int64_t p = 1; p <= 9; p++) {
      for (int64_t delta = -1; delta <= 1; delta++) {
        int64_t q = p + delta;
        if (q < 0 || q > 9) {
          continue;
        }

        if (q == 0) {
          int64_t result = p * shift;
          // cerr << result << "\n";
          cnt++;
          if (cnt == K) {
            cout << result << endl;
            return 0;
          }
          lunlun[d][p].push_back(result);
          rep(e, d - 1) {
            for (auto& l : lunlun[e][1]) {
              int64_t result = p * shift + l;
              // cerr << result << "\n";
              cnt++;
              if (cnt == K) {
                cout << result << endl;
                return 0;
              }
              lunlun[d][p].push_back(result);
            }
          }
        } else {
          for (auto& l : lunlun[d - 1][q]) {
            int64_t result = p * shift + l;
            // cerr << result << "\n";
            cnt++;
            if (cnt == K) {
              cout << result << endl;
              return 0;
            }
            lunlun[d][p].push_back(result);
          }
        }
      }
    }
  }
  return 0;
}