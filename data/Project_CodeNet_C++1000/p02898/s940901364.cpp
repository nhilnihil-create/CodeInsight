#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  rep(i, n) {
    int h;
    cin >> h;
    if(h >= k) ans++;
  }
  cout << ans << endl;
}