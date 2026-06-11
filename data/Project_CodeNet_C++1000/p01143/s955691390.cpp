#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n, m, p;
  int x[100];
  while(cin >> n >> m >> p, n + m + p) {
    int sx = 0;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      sx += x[i];
    }
    if(x[m-1] == 0) cout << 0 << endl;
    else cout << (100 - p) * sx / x[m-1] << endl;
  }
}