#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iomanip>    // fixed, setprecision
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <numeric>    // accumulate
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
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int H, W, K, cnt = 0;
  char ctmp;
  cin >> H >> W >> K;
  vector<vector<bool>> c(H, vector<bool>(W, false));
  vector<pair<int, int>> black;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> ctmp;
      if (ctmp == '#') black.push_back(make_pair(i, j));
    }
  }

  int mhm = pow(2, H), mwm = pow(2, W);
  for (int hmask = 0; hmask < mhm; hmask++) {
    for (int wmask = 0; wmask < mwm; wmask++) {
      int bc = 0;
      for (auto ij : black) {
        if ((((hmask >> get<0>(ij)) & 1) == 0) &&
            (((wmask >> get<1>(ij)) & 1) == 0))
          bc++;
      }
      if (bc == K) cnt++;
    }
  }
  cout << cnt << endl;
}
