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
  int N, s = 0;
  cin >> N;
  vector<int> A(N), B(N), C(N - 1);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> B.at(i);
  }
  for (int i = 0; i < N - 1; i++)
  {
    cin >> C.at(i);
  }

  for (int i = 0; i < N; i++)
  {
    s += B[A[i] - 1];
    if ((i != 0) && (A[i] - A[i - 1] == 1))
    {
      s += C[A[i - 1] - 1];
    }
  }
  cout << s << endl;
}
