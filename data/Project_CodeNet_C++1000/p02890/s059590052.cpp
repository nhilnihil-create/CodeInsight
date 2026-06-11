#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a(n), num(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    num.at(a.at(i) - 1)++;
  }
  
  vector<int> discard(n + 1); // discard[i]: How many cards you can NOT eat when you operate i times
  for (int i = 0; i < n; i++) {
    if (num.at(i) == 0) continue;
    discard.at(num.at(i) - 1)++;
  }
  // imos
  for (int loop = 0; loop < 2; loop++) {
    for (int i = n - 1; i >= 0; i--) {
      discard.at(i) += discard.at(i + 1);
    }
  }
  
  for (int k = 1; k <= n; k++) {
    int l = 0, r = n / k + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (k * mid <= n - discard.at(mid)) l = mid;
      else r = mid;
    }
    cout << l << '\n';
  }
}