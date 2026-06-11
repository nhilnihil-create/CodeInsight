#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> x(N), y(N);
  for(int i=0; i<N; ++i) cin >> x[i] >> y[i];
  
  using P = pair<double, int>;
  vector<P> r(N);
  for(int i=0; i<N; ++i) {
    if(x[i] == 0.0 && y[i] == 0.0) r[i] = P(0,i);
    else r[i] = P(atan2(y[i], x[i]), i);
  }
  sort(begin(r), end(r));
  
  double res = 0.0;
  for(int i=0; i<N; ++i) {
    for(int j=1; j<=N; ++j) {
      double X = 0, Y = 0;
      for(int k=i; k<i+j; ++k) {
        int c = r[k % N].second;
        X += x[c];
        Y += y[c];
      }
      res = max(res, X * X + Y * Y);
    }
  }
  cout << fixed << setprecision(15) << sqrt(res) <<endl;
}
