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
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;


int main()
{
  int n;
  cin >> n;
  vpii data(n);
  ll sum = 0;
  bool A = true;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    data[i] = make_pair(b, a);
  }
  sort(data.begin(), data.end());
  for (int i = 0; i < n; i++)
  {
    int b, a;
    tie(b, a) = data[i];
    sum += a;
    if (sum > b)
    {
      A = false;
      break;
    }
  }
  if (A)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}