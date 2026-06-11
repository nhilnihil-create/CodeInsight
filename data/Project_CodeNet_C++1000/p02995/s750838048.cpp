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
  ll A, B, C, D, N, c, d, n;
  cin >> A >> B >> C >> D;

  ll x, y = C, z = D;
  if (z > y) swap(y, z);
  while (z != 0) {
    x = y;
    y = z;
    z = x % y;
  }
  N = (C * D) / y;

  c = B / C - (A - 1) / C;
  d = B / D - (A - 1) / D;
  n = B / N - (A - 1) / N;

  cout << B - A + 1 - c - d + n << endl;
}
