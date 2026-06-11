#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
  int p,q,r;
  cin >> p >> q >> r;
  int a=fmax(p,q);
  a=fmax(a,r);
  cout << p+q+r-a;
  return 0;
}