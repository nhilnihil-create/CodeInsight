#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  ll rnum = 0;
  ll gnum = 0;
  ll bnum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') rnum++;
    else if (s[i] == 'G') gnum++;
    else if (s[i] == 'B') bnum++;
  }
  ll ans = rnum * gnum * bnum;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; 2 * j - i < n; j++) {
      if (s[i] == s[j]) continue;
      if (s[i] == s[2 * j - i]) continue;
      if (s[j] == s[2 * j - i]) continue;
      ans--;
    }
  }
  cout << ans << endl;

  return 0;
}
