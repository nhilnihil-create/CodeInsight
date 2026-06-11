#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int ans = 0;
  rep(v, 1000) {
    vector<int> a(3);
    a[0] = v / 100;
    a[1] = v / 10 - (v / 100) * 10;
    a[2] = v % 10;

    int now = 0;
    rep(i,n) {
      if ((int)(s[i] - '0') == a[now]) now++;
      if (now == 3){
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}