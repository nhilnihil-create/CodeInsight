#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int x[1000],y[1000];

double dist(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return pow(dx*dx+dy*dy, 0.5);
}

int main() {
  int n; cin >> n;
  rep(i,n) cin >> x[i] >> y[i];

  std::vector<int> v(n);
  rep(i,n) v[i] = i;

  double total = 0;
  do {
    rep(i,n-1) total += dist(v[i],v[i+1]);
  } while (next_permutation(v.begin(), v.end()));

  int f = 1;
  for (int i = 2; i <= n; i++) f *= i;
  cout << fixed << setprecision(10) << total / f << endl;
}
