#include <iostream>
using namespace std;
long long gcd(long long x,long long y){
  if (x%y == 0) return(y);
  else  return(gcd(y, x%y));
}
long long lcm(long long x,long long y){
  return x*y/gcd(x,y);
}
int main(){
  long long a,b,c,d;
  cin >> a >> b >> c >> d;
  cout << b-(a-1)-b/c+(a-1)/c-b/d+(a-1)/d+b/lcm(c,d)-(a-1)/lcm(c,d) << "\n";
  return 0;
}