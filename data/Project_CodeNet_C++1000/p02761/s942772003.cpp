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
  int N, M, s, c;
  cin >> N >> M;
  vector<int> dup(N, -1);
  for (int i = 0; i < M; i++) {
    cin >> s >> c;
    s--;
    if (dup[s] != -1 && dup[s] != c) {  // conflict
      cout << "-1" << endl;
      return 0;
    }
    dup[s] = c;
  }

  if (dup[0] == 0 && N != 1) {
    cout << "-1" << endl;
    return 0;
  }

  if (dup[0] == -1 && N != 1) {
    dup[0] = 1;
  }

  for (auto v : dup) {
    cout << (v == -1 ? 0 : v);
  }
  cout << endl;
}
