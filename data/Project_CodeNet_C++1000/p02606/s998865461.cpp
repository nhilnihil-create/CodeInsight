#include<bits/stdc++.h>
using namespace std;
int main() {
  int l, r, d; cin >> l >> r >> d;
  int res = 0;
  for (int i = l; i <= r; i++) {
    res += !(i % d != 0);
  }
  cout << res << endl;
}