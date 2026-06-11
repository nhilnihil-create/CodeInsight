#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long total = 0;
  for(int i=0; i < n; i++){
    cin >> a[i];
    total += a[i];
  }
  long long ans = 2020202040;
  long long sum = 0;
  for(int i=0; i < n; i++) {
    sum += a[i];
    ans = min(ans, abs(total-sum-sum));
  }
  cout << ans << endl;
}
