#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  ll n;
  cin >> n;
  string ans = "";
  while (n > 0)
  {
    n -= 1;
    ans += (n % 26) + 'a';
    n /= 26;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}