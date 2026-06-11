#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> Vec;

ll N;
vector<Vec> Vs;
const double EPS = 1e-10;
double R;

ll classify(Vec v, Vec w) {
  Vec dotcross = conj(v) * w;
  double dot = dotcross.real(), cross = dotcross.imag();
  return cross > EPS ? 0 : -cross > EPS ? 1 : dot > EPS ? 2 : 3;
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll x, y;
    cin >> x >> y;
    Vs.push_back(Vec(x, y));
  }
  for (Vec v : Vs) {
    Vec sum[4];
    for (Vec w : Vs) sum[classify(v, w)] += w;
    R = max({R, abs(sum[0]), abs(sum[1]), abs(sum[0] + sum[2]),
             abs(sum[1] + sum[2])});
  }
  cout << setprecision(15) << R << endl;
  return 0;
}
