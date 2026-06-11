#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

int x[10],y[10];

double dist(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return pow(dx*dx+dy*dy,0.5);
}

int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  std::vector<int> v(n);
  rep(i,n) v[i] = i + 1;
  double sum = 0.0;
  do {
    rep(i,n-1) sum += dist(v[i], v[i+1]);
  } while (next_permutation(v.begin(), v.end()));

  int f = 1;
  for (int i = 2; i <= n; i++) f *= i;
  cout << fixed << setprecision(10) << sum / f << endl;
}
