#include <bits/stdc++.h>

using namespace std;
const int N = 105;

int n, a[N], ans = 0;

inline bool check(int a, int b, int c) {
  if (a + b > c && a + c > b && b + c > a) return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) 
    cin >> a[i];
  
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      for (int k = j + 1; k <= n; ++k)
        if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k] && check(a[i], a[j], a[k])) {
          // cout << i << " " << j << " " << k << " " << endl;
          ans++;
        }
  cout << ans;
}