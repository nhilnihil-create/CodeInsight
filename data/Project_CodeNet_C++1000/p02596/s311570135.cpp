#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const int iINF = 0x3f3f3f3f;
const long long INF = 1LL << 60;
using namespace std;
using pint = pair<int, int>;

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int k;
  cin >> k;
  int s = 7;
  bool found = false;
  rep(i, k)
  {
    if (s % k == 0)
    {
      cout << i + 1 << endl;
      found = true;
      break;
    }

    s = s % k * 10 + 7;
  }

  if (!found)
    cout << -1 << endl;
  return 0;
}
