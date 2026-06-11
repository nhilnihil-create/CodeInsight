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
  ll N, ans = 0, k;
  cin >> N;

  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<bool> eras((ll)sqrt(N) + 1, true);
  for (ll i = 4; i < eras.size(); i += 2) eras[i] = false;
  if (N % 2 != 0) {
    eras[2] = false;
  } else {
    k = 2;
    while (N % k == 0) {
      N /= k;
      k *= 2;
      ans++;
    }
    while (N % 2 == 0) N /= 2;
  }

  for (ll i = 3; i < eras.size(); i += 2) {
    if (eras[i] == false) continue;
    for (ll j = i * 2; j < eras.size(); j += i) eras[j] = false;
    if (N % i != 0) {
      eras[i] = false;
    } else {
      k = i;
      while (N % k == 0) {
        N /= k;
        k *= i;
        ans++;
      }
      while (N % i == 0) N /= i;
    }
  }

  if (N > eras.size()) ans++;

  cout << ans << endl;
}
