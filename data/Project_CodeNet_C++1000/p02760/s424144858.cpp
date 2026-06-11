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
  vector<int> bingo(100, -1);
  int N, d, n;
  vector<bool> opened(9, false);

  for (int i = 0; i < 9; i++)
  {
    cin >> n;
    bingo[n - 1] = i;
  }
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> d;
    if (bingo[d - 1] != -1)
    {
      opened[bingo[d - 1]] = true;
    }
  }
  if (
      (opened[0] && opened[1] && opened[2]) ||
      (opened[3] && opened[4] && opened[5]) ||
      (opened[6] && opened[7] && opened[8]) ||
      (opened[0] && opened[3] && opened[6]) ||
      (opened[1] && opened[4] && opened[7]) ||
      (opened[2] && opened[5] && opened[8]) ||
      (opened[0] && opened[4] && opened[8]) ||
      (opened[2] && opened[4] && opened[6]))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
