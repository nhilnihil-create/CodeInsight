#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  if(b == 1) {
    cout << 0 << endl;
    return 0;
  }
  int p = 1;
  for(int i=1; ; i++) {
    p -= 1;
    p += a;
    if(b <= p) {
      cout << i << endl;
      return 0;
    }
  }
}