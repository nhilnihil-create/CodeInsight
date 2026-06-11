#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  
  vector<int> a(n);
  if (s == (int)1e9) {
    rep(i, n) {
      if (i < k) a[i] = s;
      else a[i] = 1;
    }
  } else {
    rep(i, n) {
      if (i < k) a[i] = s;
      else a[i] = s + 1;
    }
  }
  printf("%d", a[0]);
  for (int i = 1; i < n; ++i) printf(" %d", a[i]);
  printf("\n");
  return 0;
}