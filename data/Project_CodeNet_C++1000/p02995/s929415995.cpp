#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
  ll r = a%b;
  while(r > 0){
    a = b;
    b = r;
    r = a%b;
  }
  
  return b;
}

ll lcm(ll a, ll b){
  return a*b/gcd(a,b);
}

int main() {
  ll A,B,C,D;
  cin >> A >> B >> C >> D;
  //cout << gcd(A,B) << endl;
  ll num1 =  B - B/C - B/D + B/lcm(C,D);
  ll num2 = (A-1) - (A-1)/C - (A-1)/D + (A-1)/lcm(C,D);
  cout << num1 - num2 << endl;
  
  return(0);
}