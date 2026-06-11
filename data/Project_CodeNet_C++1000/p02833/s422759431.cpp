#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define MOD 1000000007

int main()
{
  ll n;
  ll res = 0;
  cin >> n;
  if (n % 2 == 0) {
    n /= 2;
    while (n > 0) {
      n /= 5;
      res += n;
    }
  }
  cout << res << endl;

  return 0;
}
