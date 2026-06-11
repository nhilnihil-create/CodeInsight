#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> cnt;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    if (cnt[a[i]] == 2) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}