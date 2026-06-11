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

int main() {
  int N, a, m = 0, nm = 0, mi = 0;
  cin >> N;
  cin >> m;
  for (int i = 1; i < N; i++) {
    cin >> a;
    if (a > m) {
      nm = m;
      m = a;
      mi = i;
    } else if (a > nm) {
      nm = a;
    }
  }
  for (int i = 0; i < N; i++) {
    if (i == mi) cout << nm << endl;
    if (i != mi) cout << m << endl;
  }
}
