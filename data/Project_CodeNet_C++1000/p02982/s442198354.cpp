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
  int N, D, c = 0;
  double d;
  cin >> N >> D;
  vector<vector<double>> X(N, vector<double>(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> X[i][j];
    }
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      d = 0.0;
      for (int dim = 0; dim < D; dim++) {
        d += pow(X[i][dim] - X[j][dim], 2.0);
      }
      d = sqrt(d);
      if (d == floor(d)) c++;
    }
  }
  cout << c << endl;
}
