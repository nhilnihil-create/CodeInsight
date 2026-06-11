#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  double d = 0;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i];
  rep(i, n) cin >> y[i];

  rep(i, 3) {
    d = 0;
    rep(j, n) {
      d += pow(abs(x[j] - y[j]), i + 1);
    }
    printf("%f\n", pow(d, 1. / double(i + 1)));
  }

  d = 0;
  rep(i, n) d = max(d, double(abs(x[i] - y[i])));
  printf("%f\n", d);  

  return 0;
}
