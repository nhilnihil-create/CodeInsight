#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int x;
  cin >> x;

  ll ans = 1;
  while(1){
    if (ans * x % 360 == 0) {
      cout << ans << endl;
      return 0;
    }
    ans++;
  }
}