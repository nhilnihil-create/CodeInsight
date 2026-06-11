#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n - k; i++) {
    cout << (a[i] < a[i + k] ? "Yes" : "No") << '\n';
  }

  return 0;
}

