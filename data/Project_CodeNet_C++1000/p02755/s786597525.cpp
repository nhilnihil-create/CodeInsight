#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c, d;
  cin >> a >> b;
  c = (a+1)/0.08, d = (b+1)/0.1;
  a /= 0.08, b /= 0.1;
  if(a!=int(a)) a=int(a)+1;
  if(b!=int(b)) b=int(b)+1;
  if(c!=int(c)) c=int(c);
  else c=int(c)-1;
  if(d!=int(d)) d=int(d);
  else d=int(d)-1;
  
  if(a<=b && d<=c) cout << b << endl;
  else if(a<=d && d<=c) cout << a << endl;
  else if(a<=b && b<=c) cout << b << endl;
  else cout << -1 << endl;
  return 0;
}