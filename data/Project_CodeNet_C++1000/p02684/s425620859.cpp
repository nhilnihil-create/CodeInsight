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
  ll N, K, j = 0, c = 1;
  cin >> N >> K;
  vector<ll> A(N + 1), B, E(N + 1, -1);
  for (ull i = 1; i <= N; i++) {
    cin >> A.at(i);
  }

  while (E[c] == -1) {
    B.push_back(c);
    E[c] = j;
    c = A[c];
    j++;
  }

  ll first = E[c];
  ll loop = j - first;
  cout << (K < j ? B[K] : B[((K - first) % loop) + first]) << endl;
}
