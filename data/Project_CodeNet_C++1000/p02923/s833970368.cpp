#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  int n, h[100010], left, cnt = 0, maxcnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> h[i];
  left = h[0];
  for (int i = 1; i < n; ++i)
  {
    if (left >= h[i])
    {
      ++cnt;
    }
    else
    {
      if (maxcnt < cnt) maxcnt = cnt;
      cnt = 0;
    }
    left = h[i];
  }
  if (maxcnt < cnt) maxcnt = cnt;

  cout << maxcnt;
}
