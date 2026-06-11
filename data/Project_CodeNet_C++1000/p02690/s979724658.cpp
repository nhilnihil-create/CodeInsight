#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int x;
  cin >> x;
  for(int a = 1; a < 1000; a++) {
    ll a5 = 1;
    rep(i, 5) a5 *= a;
    for(int b = -1000; b < 1000; b++) {
      ll b5 = 1;
      rep(i, 5) b5 *= b;
      if(a5 - b5 == x) {
        cout << a << " " << b;
        return 0;
      }
    }
  }
}
