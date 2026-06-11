#include <bits/stdc++.h>

using namespace std;

const int INF = 2000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;

  int zmax = -INF, zmin = INF, wmax = -INF, wmin = INF;
  for(int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    
    zmax = max(zmax, x + y);
    zmin = min(zmin, x + y);
    wmax = max(wmax, x - y);
    wmin = min(wmin, x - y);
  }

  cout << max(zmax - zmin, wmax - wmin) << "\n";
  return 0;
}
