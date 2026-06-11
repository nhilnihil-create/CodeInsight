#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < k; i++) {
    vector<int> b(n + 1);
    for (int j = 0; j < n; j++) {
      int l = max(0, j - a[j]);
      int r = min(n, j + a[j] + 1);
      b[l]++;
      b[r]--;
    }
    for (int j = 0; j < n; j++) {
      b[j + 1] += b[j];
    }
    b.pop_back();
    if (a == b) break;
    a = b;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;;
  }
  return 0;
}