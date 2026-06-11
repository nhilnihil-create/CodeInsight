#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i ++) {
      cin >> a[i];
      sum += a[i];
    }
    double av = (double)sum / n;

    double ans = 0;
    for (int i = 0; i < n; i ++) {
      ans += (a[i] - av) * (a[i] - av);
    }
    ans /= n;

    cout << setprecision(15) << sqrt(ans) << endl;
  }
}

