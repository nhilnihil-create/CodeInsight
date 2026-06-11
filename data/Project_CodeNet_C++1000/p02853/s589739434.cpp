#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {  
  return b != 0 ? gcd(b, a % b) : a;
}//MAX
int lcm(int a, int b) { 
   return a * b / gcd(a, b);
   }
//MIN

 main() {
int x,y;
cin >> x >>y;
ll ans = 0;
 if(x==1&&y==1)ans+=400000;
 if(x==1) ans+=300000;
 if(x==2) ans+=200000;
 if(x==3) ans+=100000;
 if(y==1) ans+=300000;
 if(y==2) ans+=200000;
 if(y==3) ans+=100000;
 cout << ans << endl;
 }