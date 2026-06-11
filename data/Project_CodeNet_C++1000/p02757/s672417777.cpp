#include <bits/stdc++.h>
 
using namespace std;
 
int md;
 
int add(int x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
  return x;
}
 
int mul(int x, int y) {
  return (int)((long long)x * y % md);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> md;
  string s;
  cin >> s;
  map<int, int> m;
  long long ans = 0;
  int dec = 1;
  int cur = 0;
  if (md == 2) {
    long long cnt = 0;
	  for (int i = n - 1; i >= 0; i--) {
      int dig = (s[i] - '0');
      if (dig % 2 == 0) {
        cnt++;
      }
      ans += cnt;
    }
    cout << ans << '\n';
    return 0;
  } 
  if (md == 5) {
    long long cnt = 0;
	  for (int i = n - 1; i >= 0; i--) {
      int dig = (s[i] - '0');
      if (dig % 5 == 0) {
        cnt++;
      }
      ans += cnt;
    }
    cout << ans << '\n';
    return 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    int dig = (s[i] - '0');
    cur = add(cur, mul(dec, dig));
    if (cur == 0) ans++;
    ans += m[cur];
    m[cur]++;
    dec = mul(dec, 10);
  }
  cout << ans << '\n';
  return 0;
}