#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> b(n+1, 0);
  for (int i = n; i >= 1; --i) {
    int c = 0;
    for (int j = i; j <= n; j += i) {
      c += b[j];
    }
    if (c % 2 != a[i]) b[i] = 1;
  }

  vector<int> d;
  for (int i = 1; i <= n; ++i) if (b[i]) d.push_back(i);
  int m = d.size();

  printf("%d\n", m);
  rep(i, m-1) printf("%d ", d[i]);
  if (m > 0) printf("%d\n", d[m-1]);
  return 0;
}