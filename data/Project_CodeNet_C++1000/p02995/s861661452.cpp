#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y){
  if(x % y == 0){
    return y;
  }else{
    return gcd(y,x % y);
  }
}

long long lcm(long long x, long long y){
  return x * y / gcd(x,y);
}

int main() {
  long long a, b, c, d;
  long long aNum,bNum;
  cin >> a >> b >> c >> d;
  
  aNum = (a-1) - ((a-1) / c) - ((a-1) / d) + ((a-1) / lcm(c, d));
  bNum = b - (b / c) - (b / d) + (b / lcm(c, d));
  
  cout << bNum - aNum << endl;
}
