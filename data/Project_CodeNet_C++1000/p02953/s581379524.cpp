#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  bool bl = true;
  h[0] -= 1;
  for (int i = 1; i <= n-1; i++) {
    if (h[i] > h[i-1]) h[i]--;
    else if (h[i] < h[i-1]) bl = false;
  }
  if (bl) puts("Yes");
  else puts("No");
  return 0;
}