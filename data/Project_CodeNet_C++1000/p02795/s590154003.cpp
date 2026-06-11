#include <bits/stdc++.h>
using namespace std;

int w, h, n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> h >> w >> n;
  cout << (n / max(h, w)) + (n % max(h, w) ? 1 : 0) << endl;
  return 0;
}