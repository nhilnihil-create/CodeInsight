#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> Vec;

ll N;
vector<Vec> Vs;
const double EPS = 1e-10;
double R;

bool good(Vec v, Vec w, int sign) {
  Vec dotcross = conj(v) * w;
  double dot = dotcross.real(), cross = dotcross.imag();
  cross *= sign;
  return cross > EPS || (abs(cross) <= EPS && dot > EPS);
}

int main() {
  cin >> N;
  for (ll i = 0; i < N; ++i) {
    ll x, y;
    cin >> x >> y;
    Vs.push_back(Vec(x, y));
  }
  for (Vec v : Vs) {
    for (int sign = -1; sign <= 1; sign += 2) {
      Vec sum;
      for (Vec w : Vs) {
        if (good(v, w, sign)) {
          sum += w;
        }
      }
      R = max(R, abs(sum));
      sum -= v;
      R = max(R, abs(sum));
    }
  }
  cout << setprecision(15) << R << endl;
  return 0;
}
