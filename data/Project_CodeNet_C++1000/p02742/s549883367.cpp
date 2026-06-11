#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  long long H, W;
  cin >> H >> W;
  long long table = H * W;
  if (H == 1 || W == 1) cout << 1;
  else {
    if (table % 2 == 0) cout << table / 2;
    else cout << (table + 1) / 2;
  }
}
