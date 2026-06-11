#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  int s = max(h, w);
  cout << (n + s - 1) / s << '\n';
  return 0;
}
