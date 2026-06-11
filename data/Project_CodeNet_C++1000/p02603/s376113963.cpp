#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <limits>
#include <tuple>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(c) c.begin(), c.end()

// greedy
int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }
  ll ans = 1000;
  rep(i, N - 1)
  {
    if (A[i] < A[i + 1])
    {
      auto x = A[i + 1] - A[i];
      auto n = ans / A[i];
      ans += x * n;
    }
  }
  cout << ans << endl;
  return 0;
}
