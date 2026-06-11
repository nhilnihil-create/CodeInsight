#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C; cin >> A >> B >> C;
  if (A-B <= C) cout << C-A+B;
  else cout << 0;
}