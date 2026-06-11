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
  string S, pre, post;
  char c;
  int opc, pos;
  ll Q;
  bool flipped = false;
  cin >> S >> Q;
  for (ll i = 0; i < Q; i++) {
    cin >> opc;
    if (opc == 1) {
      flipped = !flipped;
    } else {
      cin >> pos >> c;
      if ((pos == 1 && !flipped) || (pos == 2 && flipped)) {
        pre.push_back(c);
      } else {
        post.push_back(c);
      }
    }
  }
  reverse(pre.begin(), pre.end());
  S = pre + S + post;

  if (flipped) reverse(S.begin(), S.end());

  cout << S << endl;
}
