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
using namespace std;

int main()
{
  int N;
  uint64_t ans = 1;
  uint64_t mm = pow(10, 18);

  cin >> N;
  vector<uint64_t> a(N);

  for (int i = 0; i < N; i++)
  {
    cin >> a.at(i);
  }
  sort(a.rbegin(), a.rend());
  if (a.back() == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  for (auto v : a)
  {
    if (v > mm / ans)
    {
      cout << -1 << endl;
      return 0;
    }
    ans *= v;
  }

  cout << ans << endl;
}
