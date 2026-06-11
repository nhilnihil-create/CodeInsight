#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b;
  c = (a+1)/0.08, d = (b+1)/0.1;
  a /= 0.08, b /= 0.1;
  
  int ans = -1;
  for(int i=min(a,b); i<=max(c,d); i++) {
    if(a<=i && i<c && b<=i && i<d) {
      ans = i;
      break;
    }
  }
  
  cout << ans << endl;
  return 0;
}