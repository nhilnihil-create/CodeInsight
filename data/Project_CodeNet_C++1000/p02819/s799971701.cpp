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
  int64_t X;
  bool prime;
  cin >> X;

  while (true) {
    prime = true;
    if (X != 2 && X % 2 == 0) {
      prime = false;
    } else {
      for (int i = 3; i < sqrt(X); i += 2) {
        if (X % i == 0) {
          prime = false;
          break;
        }
      }
    }

    if (prime) break;

    X += 1;
  }
  cout << X << endl;
}
