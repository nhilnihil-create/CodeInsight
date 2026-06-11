#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
  ll H, W;
  cin >> H >>W;
  ll ans;
  ans = (H * W) / 2;
  bool flag = true;
  if( H == 1 || W == 1) {
    ans = 1;
  }
  else if( H % 2 == 1 && W % 2 == 1) {
    ans++;
    flag = false;
  }
  cout << ans << endl;
}