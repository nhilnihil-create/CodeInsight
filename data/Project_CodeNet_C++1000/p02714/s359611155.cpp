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
  ll N, c = 0;
  string s;
  ll R = 0, G = 0, B = 0;
  cin >> N >> s;
  for (int i = 0; i < N; i++) {
    switch (s[i]) {
      case 'R':
        R++;
        break;
      case 'G':
        G++;
        break;
      case 'B':
        B++;
        break;
    }
  }

  ll i, j, k;
  for (ll diff = 1; diff <= N / 2; diff++) {
    for (i = 0; i < N; i++) {
      j = i + diff;
      k = j + diff;
      if (k < N) {
        if (s[i] != s[k] && s[j] != s[k] && s[i] != s[j]) c--;
      } else {
        break;
      }
    }
  }

  c += R * G * B;

  cout << c << endl;
}
