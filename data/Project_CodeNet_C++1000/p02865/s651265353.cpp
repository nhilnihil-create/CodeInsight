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
int n;
cin >> n;
if(n%2==0){
    cout << n/2-1<<endl;
}
else{
    cout << n/2<<endl;
}
}
