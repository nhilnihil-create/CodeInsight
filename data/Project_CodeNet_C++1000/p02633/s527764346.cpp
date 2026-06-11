/* A - Takahashikun, The Strider */

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  int r;
  r = a % b;
  if(r == 0) return b;
  else return gcd(b, r);
}

int main(){
  int X, G;
  cin >> X;
  G = gcd(X, 360);
  cout << 360 / G << endl;
}