#include <algorithm>
#include <cmath>
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
  vector<int> freq(N, 0);
  rep(i, N) {
    int a;
    cin >> a;
    a--;
    freq[a]++;
  }
  sort(freq.begin(), freq.end());
  vector<int> acc(1, 0);
  copy(freq.begin(), freq.end(), back_inserter(acc));
  rep(i, N) { acc[i + 1] += acc[i]; }

  vector<int> result(N);
  int j = 1;
  rrep(i, N) {
    const int K = i + 1;
    while (true) {
      const int m = lower_bound(freq.begin(), freq.end(), j) - freq.begin();
      bool cond = false;
      if (N - m >= K) {
        cond = true;
      } else {
        int L = K - (N - m);
        if (acc[m] >= j * L) {
          cond = true;
        }
      }

      if (cond) {
        j++;
      } else {
        break;
      }
    }
    result[i] = j - 1;
  }

  rep(i, N) { cout << result[i] << "\n"; }
  return 0;
}