#include <algorithm>
#include <iostream>

using namespace std;

int n, k, sum_a, ans;
int a[550];
int r[550];

int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum_a += a[i];
  }
  
  for (int mod = 1; mod * mod <= sum_a; mod++) {
    if (sum_a % mod) continue;
    
    int sum_r = 0;
    for (int i = 0; i < n; i++) {
      r[i] = a[i] % mod;
      sum_r += r[i];
    }
    sort(r, r+n);
    int cnt_x = sum_r, cnt_y = 0;
    for (int i = n-1; i >= 0; i--) {
      cnt_x -= r[i];
      cnt_y += mod - r[i];
      if (cnt_x == cnt_y) break;
    }
    if (cnt_x <= k) ans = max(ans, mod);
    
    int mod2 = sum_a / mod;
    sum_r = 0;
    for (int i = 0; i < n; i++) {
      r[i] = a[i] % mod2;
      sum_r += r[i];
    }
    sort(r, r+n);
    cnt_x = sum_r, cnt_y = 0;
    for (int i = n-1; i >= 0; i--) {
      cnt_x -= r[i];
      cnt_y += mod2 - r[i];
      if (cnt_x == cnt_y) break;
    }
    if (cnt_x <= k) ans = max(ans, mod2);
  }
  
  cout << ans << endl;
  return 0;
}