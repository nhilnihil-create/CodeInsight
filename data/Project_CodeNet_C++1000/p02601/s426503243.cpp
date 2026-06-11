#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  string ans = "No";
  rep(i,k) {
    if(b >= c) c *= 2;
    else if(a >= b) b *= 2;
    if(a < b && b < c) {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
}