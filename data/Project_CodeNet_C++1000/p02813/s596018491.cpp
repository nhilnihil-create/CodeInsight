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

int f(int x) {
  int y = 1;
  for (int i = 1; i <= x; i++) {
    y *= i;
  }
  return y;
}

int main() {
  ll N, p = 0, q = 0;
  cin >> N;
  vector<ll> P(N), Q(N), pu(N, 0), qu(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
    P[i]--;
    pu[P[i]] = 1;
    for (int j = 0; j < P[i]; j++) {
      if (pu[j] == 0) p += f(N - 1 - i);
    }
  }
  for (int i = 0; i < N; i++) {
    cin >> Q.at(i);
    Q[i]--;
    qu[Q[i]] = 1;
    for (int j = 0; j < Q[i]; j++) {
      if (qu[j] == 0) q += f(N - 1 - i);
    }
  }

  cout << abs(q - p) << endl;
}
