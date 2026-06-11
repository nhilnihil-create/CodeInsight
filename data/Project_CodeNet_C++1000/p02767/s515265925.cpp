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
  int N, cc;
  cin >> N;
  vector<int> x(N), c(100, 10000 * N);
  for (int i = 0; i < N; i++)
  {
    cin >> x.at(i);
  }
  sort(x.begin(), x.end());
  for (int p = x.front(); p <= x.back(); p++)
  {
    cc = 0;
    for (auto xx : x)
    {
      cc += pow(xx - p, 2);
    }
    c[p - 1] = cc;
  }
  cout << *min_element(c.begin(), c.end()) << endl;
}
