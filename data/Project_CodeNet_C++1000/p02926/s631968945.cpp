#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <complex>
#include <random>
using namespace std;

random_device rd;
mt19937 mt(rd());

using Point = complex<double>;
double dot(Point p, Point q) { return (conj(p) * q).real(); }

int n;
double x, y;
vector<Point> ps;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> x >> y;
    ps.emplace_back(x, y);
  }

  double ans = 0.0;
  uniform_real_distribution<> rand(-1.0, 1.0);
  for(int unko = 0; unko < 100000; ++unko) {
    vector<Point> engines;
    Point move(rand(mt), rand(mt));
    for(int i = 0; i < n; ++i) {
      if(dot(move , ps[i]) >= 0) {
        engines.push_back(ps[i]);
      }
    }

    x = 0.0, y = 0.0;
    for(auto engine : engines) {
      x += engine.real(), y += engine.imag();
    }
    ans = max(ans, sqrt(x*x + y*y));
  }
  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}