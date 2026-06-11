#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) a[i]--;

  vector<int> b(n);
  rep(i, n) b[a[i]] = i + 1;

  printf("%d", b[0]);
  for (int i = 1; i < n; ++i) printf(" %d", b[i]);
  printf("\n");
  return 0;
}