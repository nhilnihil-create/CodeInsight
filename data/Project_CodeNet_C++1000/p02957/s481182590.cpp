#include<bits/stdc++.h>
using namespace std;

signed main() {
  int a,b;
  cin >> a >> b;
  int d = abs(a-b);
  if (d % 2 ) { puts("IMPOSSIBLE"); return 0;}
  cout << max(a,b) - d/2 << endl;
}
