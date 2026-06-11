#include <bits/stdc++.h>

using namespace std;
typedef long long vlong;

vlong lcm(vlong x,vlong y){
 return (x/__gcd(x,y))*y;
}
int main() {
  vlong n,k;
  cin >> n>>k;
   cout<<lcm(n,k);
}
