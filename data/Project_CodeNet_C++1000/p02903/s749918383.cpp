#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(i < b && j < a || i >= b && j >= a) cout << '0';
      else cout << '1';
    }
    cout << '\n';
  }

}
