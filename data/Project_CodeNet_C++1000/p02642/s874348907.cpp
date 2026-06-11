#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // int MAX = (int)1e6;
  int MAX = *max_element(a.begin(), a.end());
  vector<int> cnt(MAX + 1);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  vector<bool> good(MAX + 1, true);
  for (int i = 0; i < n; i++) {
    if (cnt[a[i]] != 0) {
      for (int j = a[i] + a[i]; j <= MAX; j += a[i]) {
        good[j] = false;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (good[a[i]] && cnt[a[i]] == 1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
