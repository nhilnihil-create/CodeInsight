#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if(a == b) cnt++;
    else cnt = 0;
    if(cnt == 3) break;
  }
  string ans;
  if(cnt == 3) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
}