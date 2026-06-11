#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int one = n%10;
  string ans;
  if (one == 3) {
      ans = "bon";
  } else if (one == 0 || one == 1 || one == 6 || one == 8) {
      ans = "pon";
  } else {
      ans = "hon";
  }
  cout << ans << endl;
  return 0;
}