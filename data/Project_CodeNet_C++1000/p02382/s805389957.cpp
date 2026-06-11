#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N);
  for (int i=0; i<N; i++) cin >> x[i];
  vector<int> y(N);
  for (int i=0; i<N; i++) cin >> y[i];

  double d1 = 0, d2 = 0, d3 = 0, d = 0;
  for (int i=0; i<N; i++) {
    d1 += abs(x[i] - y[i]);
    d2 += pow(abs(x[i] - y[i]), 2);
    d3 += pow(abs(x[i] - y[i]), 3);
    d = max(d, double(abs(x[i] - y[i])));
  }
  d2 = sqrt(d2);
  d3 = cbrt(d3);

  printf("%.5f\n%.5f\n%.5f\n%.5f\n", d1, d2, d3, d);

  return 0;
}

