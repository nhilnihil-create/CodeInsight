#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  double sum;
  rep(i, n) {
    int a;
    cin >> a;
    sum += 1.0 / a;
  }
  double ans = 1/sum;
  cout << fixed << setprecision(6);
  cout << ans;
}
