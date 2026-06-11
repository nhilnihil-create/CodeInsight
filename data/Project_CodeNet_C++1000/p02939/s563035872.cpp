#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  string S;
  cin >> S;
  int ans = 0;
  string t, p = "";
  rep(i, S.size())
  {
    t += S[i];
    if (t == p)
    {
      continue;
    }
    p = t;
    t = "";
    ans++;
  }
  cout << ans << endl;
  return 0;
}