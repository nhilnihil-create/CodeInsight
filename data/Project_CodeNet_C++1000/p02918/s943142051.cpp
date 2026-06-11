#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  if (n == 1)
  {
    puts("0");
    return 0;
  }
  rep(i, n)
    if (s[i] == 'R' && i != n - 1 && s[i+1] == 'R')
      ans++;
    else if (s[i] == 'L' && i != 0 && s[i-1] == 'L')
      ans++;
  ans += k * 2;
  cout << min(ans, n - 1) << endl;
  return 0;
}