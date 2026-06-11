#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  map<int, int> f;
  int n;
  ll sol = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int h;
    cin >> h;
    sol += f[i - h];
    f[i + h]++;
  }
  cout << sol << "\n";

  return 0;
}
