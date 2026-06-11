#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  string S;
  cin >> S;
  ll r = 0, l = 0;
  vector<int> a(S.size() + 1);
  rep(i, S.size())
  {
    if (S.at(i) == '<')
    {
      a[i + 1] = max(a[i + 1], a[i] + 1);
    }
  }
  for (int i = S.size() - 1; i >= 0; i--)
  {
    if (S[i] == '>')
    {
      a[i] = max(a[i], a[i + 1] + 1);
    }
  }
  ll ans = 0;
  rep(i, S.size() + 1)
  {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}