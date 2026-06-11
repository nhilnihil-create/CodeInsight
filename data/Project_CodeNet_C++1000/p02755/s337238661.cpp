#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main()
{
  double a, b;
  cin >> a >> b;
  rep(n, 10000)
  {
    int za = n * 8 / 100;
    int zb = n * 10 / 100;
    if (a == za && b == zb)
    {
      cout << n << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}