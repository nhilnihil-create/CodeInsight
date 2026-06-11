#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  bool c = true;
  for(int i = 0; i < m; i++) cin >> a.at(i);
  for (int A : a) {
    n -= A;
    if(n < 0) {
      c = false;
      break;
    }
  }
  if(c) cout << n << endl;
  else cout << -1 << endl;
}