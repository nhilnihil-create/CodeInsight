#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string ans;

  if (a== b && b==c) {
    ans = "No";;
  }else if (a== b || b==c || a==c) {
    ans = "Yes";
  }else{
  ans = "No";
  }
  cout << ans << endl;

  return 0;
}