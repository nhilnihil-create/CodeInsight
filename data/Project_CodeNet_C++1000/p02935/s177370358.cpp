#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  double res = (a[0] + a[1]) / 2;
  for (int i = 2; i < N; ++i) {
    res = (res + a[i]) / 2;
  }
  cout << fixed << setprecision(10) << res << endl;
}