#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int X[10][10];

int main() {
  int N, D;
  cin >> N >> D;
  rep(i,N) rep(j,D) cin >> X[i][j];
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i+1; j < N; ++j) {
      int d = 0;
      rep(k,D) d += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
      int t = sqrt(d);
      if (t*t == d) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}