#include <bits/stdc++.h>
using namespace std;

int main() {
  int p,q,r;
  cin >> p >> q >> r;
  int m=max(p,q);
  m=max(m,r);
  int s=p+q+r;
  cout << s-m << endl;
}
