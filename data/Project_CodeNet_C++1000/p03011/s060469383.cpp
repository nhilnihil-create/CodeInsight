#include<bits/stdc++.h>
using namespace std;
int main(){
  int p,q,r;
  cin >> p >> q >> r;
  int a=p+q;
  int b=q+r;
  int c=r+p;
  if(a<=b && a<=c) cout << a << endl;
  if(b<a && b<=c) cout << b << endl;
  if(c<b && c<a) cout << c << endl;
  return 0;
}