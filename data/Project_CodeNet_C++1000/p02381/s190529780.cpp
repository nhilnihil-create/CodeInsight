#include <bits/stdc++.h> 

using namespace std; 

int main() {
  cout << fixed << setprecision(12);
  while (true) {
    int n;
    double a[1000], sum = 0, avg, ans = 0;
    cin >> n;
    if (!n) {
      break;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    avg = sum / n;
    for (int i = 0; i < n; i++) {
      ans += pow(a[i] - avg, 2);
    }
    ans = sqrt(ans / n);
    cout << ans << '\n';
  }
  return 0;
}

