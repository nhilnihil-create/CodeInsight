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
typedef long long ll;
typedef unsigned long long ull;

int main() {
  ll L, R, im, mo, mi = 2019;
  cin >> L >> R;

  for (ll i = L; i <= min(R - 1, L + 2019); i++) {
    im = i % 2019;
    for (ll j = i + 1; j <= min(R, i + 2020); j++) {
      mo = (im * j) % 2019;
      mi = min(mi, mo);
    }
  }
  cout << mi << endl;
}
