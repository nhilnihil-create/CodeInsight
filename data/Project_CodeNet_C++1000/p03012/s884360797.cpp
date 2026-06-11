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
  int N, s0 = 0, s1 = 0, m = 100000, d;
  cin >> N;
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
    s1 += W[i];
  }

  for (int i = 0; i < N; i++) {
    s1 -= W[i];
    s0 += W[i];
    d = abs(s1 - s0);
    m = min(m, d);
  }
  cout << m << endl;
}
