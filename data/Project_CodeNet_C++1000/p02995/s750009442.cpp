#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;
long a,b,c,d;
long gcd(long x,long y){
      return (x % y == 0) ? y : gcd(y,x % y);
}
long lcm(long x,long y){
      return x * y / gcd(x,y);
}
long f(long l){
      long t = l / c + l / d - l / lcm(c,d);
      return l - t;
}
int main(void){
      cin >> a >> b >> c >> d;
      cout << f(b) - f(a - 1) << endl;
}
