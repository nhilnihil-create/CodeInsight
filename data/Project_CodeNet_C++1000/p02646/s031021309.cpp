#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265359

//階乗
ll factorial(ll num){ll sum = 1; for(ll i=1;i<=num;i++) sum*=i; return sum;}
//素数判定
bool isPrime(ll num){if(num<2){return false;}else if(num==2){return true;}else if(num%2==0){return false;} double sqrtNum=sqrt(num);for(int i=3;i<=sqrtNum;i+=2){if(num%i==0)return false;}return true;}

int main(){
  ll a,b,v,w,t;
  cin >> a >> v >> b >> w >> t;
  
  if(a >= b){
    if(a-v*t <= b-w*t) cout << "YES" << endl;
    else cout << "NO" << endl;
  }else if(a < b){
    if(a+v*t >= b+w*t) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}