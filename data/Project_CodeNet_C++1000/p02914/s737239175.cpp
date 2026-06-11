#include <iostream>
#include <algorithm>
using namespace std;
long n, all, a[100010];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
    all ^= a[i];
  }
  for(int i = 0; i < n; ++i) a[i] &= ~all;

  for(int i = 0; i < n; ++i) {
    int idx = max_element(a + i, a + n) - a;
    if(a[idx] == 0) break;
    swap(a[i], a[idx]);
    long msb = 1;
    while(msb << 1 <= a[i]) msb <<= 1;
    for(int j = 0; j < n; ++j) if(i != j && a[j] & msb) a[j] ^= a[i];
  }

  long ans = 0;
  for(int i = 0; i < n; ++i) ans = max(ans, ans ^ a[i]);
  cout << ans * 2 + all;
  return 0;
}