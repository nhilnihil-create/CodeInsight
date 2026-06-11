#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (b-a&1) puts("IMPOSSIBLE");
  else cout << (b+a)/2 << '\n';  
  return 0;
}