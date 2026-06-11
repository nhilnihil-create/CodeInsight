#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double sum = 0;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    double b = a;
    sum += 1 / b;
  }
  double ans = 1 / sum;
  cout << fixed << setprecision(6) << ans << endl;
}