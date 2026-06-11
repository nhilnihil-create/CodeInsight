#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iomanip>    // fixed, setprecision
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <queue>      // queue, priority_queue
#include <set>        // set
#include <stack>      // stack
#include <string>     // string, to_string, stoi
#include <tuple>      // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
using namespace std;

const int IMPOSSIBLE = 10e+5 * 12 + 1;

int dp(const vector<int> &price, const vector<vector<int>> &skill,
       vector<int> acquired, int X, int M, int N, int layer, int cprice) {
  if (all_of(acquired.begin(), acquired.end(), [X](int x) { return x >= X; })) {
    return cprice;
  }

  if (layer == N) return IMPOSSIBLE;

  int a, b;
  vector<int> nacquired(acquired);
  for (int i = 0; i < M; i++) {
    nacquired[i] += skill[layer][i];
  }
  a = dp(price, skill, nacquired, X, M, N, layer + 1, cprice + price[layer]);
  b = dp(price, skill, acquired, X, M, N, layer + 1, cprice);

  return min(a, b);
}

int main() {
  int N, M, X, m;
  cin >> N >> M >> X;
  vector<vector<int>> skill(N, vector<int>(M));
  vector<int> price(N), acquired(M, 0);
  for (int i = 0; i < N; i++) {
    cin >> price.at(i);
    for (int j = 0; j < M; j++) {
      cin >> skill[i][j];
    }
  }

  m = dp(price, skill, acquired, X, M, N, 0, 0);
  cout << (m == IMPOSSIBLE ? -1 : m) << endl;
}
