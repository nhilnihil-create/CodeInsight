#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, n; cin >> x >> n;
  unordered_set<int> ps;
  for(int i = 0; i < n; ++i) {
    int p; cin >> p;
    ps.insert(p);
  }
  for(int d = 0; ; ++d) {
    if(ps.count(x - d) == 0) {
      printf("%d\n", x - d);
      break;
    }
    if(ps.count(x + d) == 0) {
      printf("%d\n", x + d);
      break;
    }
  }
  return 0;
}
