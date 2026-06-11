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
  ll N, K, i;
  double pi, pc, ps = 0, pm = 0;
  deque<double> p;
  cin >> N >> K;

  for (i = 0; i < min(N, K); i++) {
    cin >> pi;
    pc = (pi + 1) / 2;
    p.push_back(pc);
    ps += pc;
  }
  pm = ps;

  for (; i < N; i++) {
    cin >> pi;
    pc = (pi + 1) / 2;
    p.push_back(pc);
    ps += pc;
    ps -= p.front();
    p.pop_front();
    pm = max(pm, ps);
  }

  cout << fixed << setprecision(10) << pm << endl;
}
