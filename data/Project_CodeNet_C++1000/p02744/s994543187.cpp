#include <algorithm>
#include <bitset>
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

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

void solve(vector<int> &group, int N, int M) {
  if (group.size() == N) {
    rep(i, N) { cout << (char)(group[i] + 'a'); }
    cout << "\n";
  } else {
    irep(i, M) {
      group.push_back(i);
      solve(group, N, M);
      group.pop_back();
    }

    group.push_back(M + 1);
    solve(group, N, M + 1);
    group.pop_back();
  }
}

int main() {
  int N;
  cin >> N;

  vector<int> group(1, 0);
  solve(group, N, 0);

  return 0;
}