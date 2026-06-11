#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << "\n"
typedef long long ll;

int main()
{
  ll k;
  cin >> k;

  int n = 7 % k;
  ll ans = -1;
  for (int i = 1; i <= 10e6; i++)
  {
    if (n == 0)
    {
      ans = i;
      break;
    }
    n = (n * 10 + 7) % k;
  }
  cout << ans << endl;
}