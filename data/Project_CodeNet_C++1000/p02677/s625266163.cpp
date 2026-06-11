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
#include <iomanip>
using namespace std;

int main()
{
  int A, B, H, M;
  double ax, ay, aang, bx, by, bang, dist;
  cin >> A >> B >> H >> M;

  aang = (1 - (H + M / 60.0) / 12.0) * 2 * M_PI;
  bang = (1 - M / 60.0) * 2 * M_PI;
  ax = A * cos(aang);
  ay = A * sin(aang);
  bx = B * cos(bang);
  by = B * sin(bang);
  dist = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

  cout << fixed << setprecision(10) << dist << endl;
}
