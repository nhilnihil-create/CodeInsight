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
  int N;
  cin >> N;
  string s;
  cin >> s;

  vector<int> v(N);
  rep(i, N) {
    if (s[i] == 'R') {
      v[i] = 0;
    } else if (s[i] == 'G') {
      v[i] = 1;
    } else {
      v[i] = 2;
    }
  }

  vector<vector<int>> cnt(N, vector<int>(3, 0)), rcnt(N, vector<int>(3, 0));
  rep(i, N - 1) {
    copy(cnt[i].begin(), cnt[i].end(), cnt[i + 1].begin());
    cnt[i + 1][v[i]]++;
  }
  rep(i, N - 1) {
    copy(rcnt[N - 1 - i].begin(), rcnt[N - 1 - i].end(),
         rcnt[N - 1 - i - 1].begin());
    rcnt[N - 1 - i - 1][v[N - 1 - i]]++;
  }

  int64_t result = 0;
  rep(i, N) {
    result += cnt[i][(v[i] + 1) % 3] * rcnt[i][(v[i] + 2) % 3] +
              cnt[i][(v[i] + 2) % 3] * rcnt[i][(v[i] + 1) % 3];
  }

  rep(j, N) {
    for (int d = 1; j - d >= 0 && j + d < N; d++) {
      if (v[j] != v[j - d] && v[j] != v[j + d] && v[j - d] != v[j + d]) {
        result--;
      }
    }
  }

  cout << result << endl;

  return 0;
}