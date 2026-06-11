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
  ll N, x, y;
  double d, t = 0;
  cin >> N;
  vector<pair<double, double>> town(N);
  for (ll i = 0; i < N; i++) {
    cin >> x >> y;
    town[i] = make_pair(x, y);
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      d = sqrt(pow(get<0>(town[i]) - get<0>(town[j]), 2) +
               pow(get<1>(town[i]) - get<1>(town[j]), 2));
      t += d * 2;
    }
  }
  cout << fixed << setprecision(10) << t / N << endl;
}
