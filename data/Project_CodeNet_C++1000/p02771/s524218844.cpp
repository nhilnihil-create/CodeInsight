#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <time.h>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for (i = 0; i < n; i++)
#define all(c) (c).begin(), (c).end()
#define P pair<int, int>

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  bool yes = false;
  if (a == b)
  {
    if (c != a)
    {
      yes = true;
    }
  }
  else if (a == c)
  {
    if (b != a)
    {
      yes = true;
    }
  }
  else if (b == c)
  {
    if (a != b)
    {
      yes = true;
    }
  }

  if (yes)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}