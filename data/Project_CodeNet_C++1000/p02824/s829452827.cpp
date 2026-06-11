#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std; 

const int maxn = 3e5; 

int n, m, v, k; 
int a[maxn + 5]; 
int lst[maxn + 5];
long long sum[maxn + 5];  

int chk(int x) {
  if (x <= k) {
    return 1; 
  }
  if (a[x] + m < a[k]) return 0; 
  if (n - x + 1 + k - 1 >= v) {
    if (a[x] + m >= a[k]) return 1; 
    else return 0; 
  }
  int P = v - (n - x + 1) - (k - 1);  
  ll T = 0; 
  for (int i = k; i < x; i++) {
    T += min(a[x] + m - a[i], m); 
  }
  if (1ll * P * m <= T) {
    return 1; 
  }
  return 0; 
}

signed main() {  
  scanf("%lld %lld %lld %lld", &n, &m, &v, &k); 
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]); 
  }  
  sort(a + 1, a + n + 1); 
  reverse(a + 1, a + n + 1); 
  int Lst = 0; a[0] = -1; 
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[Lst]) Lst = i; 
    lst[i] = Lst; 
    sum[i] = sum[i - 1] + a[i]; 
  }
  int ans = -1, l = 1, r = n; 
  while (l <= r) {
    int mid = (l + r) >> 1; 
    if (chk(mid)) {
      l = mid + 1; ans = mid; 
    }
    else {
      r = mid - 1; 
    }
  }
  cout << ans << '\n'; 
  return 0; 
}