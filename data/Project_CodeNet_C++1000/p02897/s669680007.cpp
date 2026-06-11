#include<bits/stdc++.h>
using namespace std;
int main() {
  double a;cin >> a;
  int k;
  if((int)a%2==0)k=a/2;
  else k=(int)(a)/2+1;
  cout << fixed << setprecision(10) << k/a << endl;
  return 0;
}