#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <iomanip>       // fixed, setprecision
using namespace std;

int main()
{
  int64_t N, M, a, b;
  cin >> N >> M;
  vector<int64_t> H(N), Y(N, true);

  for (int64_t i = 0; i < N; i++)
  {
    cin >> H.at(i);
  }
  for (int64_t i = 0; i < M; i++)
  {
    cin >> a >> b;
    if (H[a - 1] > H[b - 1])
    {
      Y[b - 1] = false;
    }
    else if (H[b - 1] > H[a - 1])
    {
      Y[a - 1] = false;
    }
    else
    {
      Y[a - 1] = false;
      Y[b - 1] = false;
    }
  }
  cout << count(Y.begin(), Y.end(), true);
}
