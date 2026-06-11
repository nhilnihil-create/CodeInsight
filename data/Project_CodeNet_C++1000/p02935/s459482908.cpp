#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> value(N);
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    double v = a;
    value.at(i) = v;
  }
  sort(value.begin(), value.end());
  double ans = (value.at(0) + value.at(1)) / 2;
  for(int i = 2; i < N; i++) {
    ans = (ans + value.at(i)) / 2;
  }
  cout << fixed << setprecision(6) << ans << endl;
}