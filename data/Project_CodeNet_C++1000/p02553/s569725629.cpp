#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(){
  long a,b,c,d;
  cin >> a >> b >> c >> d;
  long x1, x2, x3, x4;
  x1 = a * c;
  x2 = a * d;
  x3 = b * c;
  x4 = b * d;
  if (x1 > x2 && x1 > x3 && x1 > x4) cout << x1;
  else if (x2 > x3 && x2 > x4) cout << x2;
  else if (x3 > x4) cout << x3;
  else cout << x4;
}