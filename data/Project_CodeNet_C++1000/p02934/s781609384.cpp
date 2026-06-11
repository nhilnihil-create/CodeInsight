#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  double ans = 0.0, num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    ans += 1.0 / num;
  }
  cout << fixed << setprecision(10);
  cout << 1.0 / ans << endl;
}
