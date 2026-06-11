#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  ll n, a;
  const int m = 26;
  string ans = "";
  cin >> n;
  while (n > 0)
  {
    n--;
    a = n % m;
    n /= m;
    ans += 'a' + a;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
}
