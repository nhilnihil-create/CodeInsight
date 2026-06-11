#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n;
  x=ceil(n/1.08);
  if(int(floor(x*1.08))==n) cout << x;
  else cout << ":(";
  return 0;
}
