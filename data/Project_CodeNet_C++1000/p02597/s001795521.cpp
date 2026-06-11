#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  string C;
  cin >> C;

  int ans = 0;
  int l = 0, r = N - 1;
  while (true) {
    while (l < N) {
      if (C[l] == 'W') break;
      l++;
    }
    while (0 <= r) {
      if (C[r] == 'R') break;
      r--;
    }
    if (r < l) break;
    ans++;
    l++;
    r--;
  }
  cout << ans << endl;
  return 0;
}