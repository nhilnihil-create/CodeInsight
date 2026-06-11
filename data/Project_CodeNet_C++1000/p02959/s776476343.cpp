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
  ll N, c = 0, B;
  cin >> N;
  vector<ll> A(N + 1);

  for (ll i = 0; i <= N; i++) {
    cin >> A[i];
  }
  for (ll i = 0; i < N; i++) {
    cin >> B;
    if (A[i] >= B) {
      c += B;
    } else {
      B -= A[i];
      c += A[i];
      if (A[i + 1] >= B) {
        c += B;
        A[i + 1] -= B;
      } else {
        c += A[i + 1];
        A[i + 1] = 0;
      }
    }
  }
  cout << c << endl;
}
