#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  if (n % 2 == 0) {
    while (n) {
      ans += n / 10;
      n /= 5;
    }
  }
  cout << ans << endl;
  return 0;
}