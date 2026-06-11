#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int p, q, r;
  cin >> p >> q >> r;
  
  int a,b,c;
  a = p+q;
  b = q+r;
  c = r+p;
  
  cout << min({a,b,c});
}