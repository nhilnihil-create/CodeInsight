#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int dur = h2 * 60 + m2 - (h1 * 60 + m1) - k;
  cout << dur << "\n";
  return 0;
}
