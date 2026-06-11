#include <bits/stdc++.h>
using namespace std;

//最大公倍数
int gcd(int x, int y){
  if(x % y == 0) return y;
  return gcd(y, x % y);
}
//最小公倍数
long long lcm(int x, int y){
  return (long long) x / gcd(x,y) * y;
}

int main() {
    int a,b; cin >> a >> b;
    cout << lcm(a,b) << endl;
}