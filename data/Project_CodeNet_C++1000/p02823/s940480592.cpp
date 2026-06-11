#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  ll ans;
  if (a % 2 == b % 2) {
    ans = (b-a) / 2;
  } else {
    if (a-1 <= n-b) {
      ans = a;
      b -= a;
      a = 1;
      ans += (b-a) / 2;
    } else {
      ans = n-b+1;
      a += n-b+1;
      b = n;
      ans += (b-a) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
