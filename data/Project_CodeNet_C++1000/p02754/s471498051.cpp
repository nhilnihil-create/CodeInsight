

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  ll a,b,c, ans;
  cin >> a >> b >> c;
  if (b == 0) {
    cout << 0 << endl;
    return 0;
  }
  ll d = b + c;
  ans = a / d * b;
  if(a % d) {
    ans += min(b, a % d);
  }
  cout << ans << endl;
  return 0;
}