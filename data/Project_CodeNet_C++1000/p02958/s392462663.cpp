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
  int N, c = 0;
  cin >> N;
  vector<int> p(N), s(N);
  for (int i = 0; i < N; i++)
  {
    cin >> p.at(i);
    s[i] = p[i];
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < N; i++)
  {
    if (p[i] != s[i])
    {
      c++;
    }
  }
  cout << ((c == 2 || c == 0) ? "YES" : "NO") << endl;
}
