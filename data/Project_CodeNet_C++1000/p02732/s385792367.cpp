#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int64_t> a(n);
  map<int64_t, int64_t> bc;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (bc.count(a[i]) == 0) bc[a[i]] = 0;
    bc[a[i]]++;
  }

  map<int64_t, int64_t> sums;
  int64_t all_sum = 0;
  for (auto count : bc) {
    sums[count.first] = count.second * (count.second - 1) / 2;
    all_sum += sums[count.first];
  }

  for (int k = 0; k < n; k++) {
    int64_t ans = all_sum;
    ans -= sums[a[k]];

    ans += (bc[a[k]] - 1) * (bc[a[k]] - 2) / 2;
    cout << ans << endl;
  }
}
