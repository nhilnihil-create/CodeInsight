#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll res = a*c;
  res = max(res,a*d);
  res = max(res,b*c);
  res = max(res,b*d);
  cout << res << endl;
  return 0;
}
