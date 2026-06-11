#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if (a % b)
    return gcd(b, a % b);
  else
    return b;
}

int lcm(int a, int b){
  return a/gcd(a,b)*b;
}

int main(){
  int d;
  int a = 360;
  int g;
  
  cin >> d;
  g = lcm(d,a);
  
  cout << g / d << endl;
  
  return 0;
}