#include <bits/stdc++.h>
using namespace std;
 
int X, Y;
 
int getRoutePatterns(int x, int y){
  if(x < 0 || y < 0) return 0;
  if(x == 0 && y==0) return 1;
  if(x == 0 && y==1) return 0;
  if(x == 1 && y == 0) return 0;
  // cout << "x:" <<x<<" y:"<<y <<"  "<< (getRoutePatterns(x-1, y-2) + getRoutePatterns(x-2,y-1)) % (int)(pow(10,9)+7)<< "\n";
  return (getRoutePatterns(x-1, y-2) + getRoutePatterns(x-2,y-1)) % (int)(pow(10,9)+7);
}

long long gcd (long long a, long long b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

long long extGCD_tobeFixed(long long a, long long b, long long &x, long long &y){
  if(b ==0){
    x=1;
    y=0;
    return a;
  }
  long long d = extGCD_tobeFixed(b,a%b,y,x);
  y -= a*x/b;
  return d;
}

void extGCD(long long a, long long b, long long &x_, long long &y_){
  long long s, t, u,v,k,x,y;
  s = a;t = b;
  x = 1; y=0; u=0;v=1;
  while(t){
    k = s/t;
    s -= k*t;
    swap(s,t);
    x -= k*u;
    y -= k*v;
    swap(x,u);
    swap(y,v);
  }
  x_ = x; y_=y;
}

long long modinv(long long a, long long m){
  long long x,y;
  extGCD(a,m,x,y);
  if(x<0) return x+m;
  return x;
}

const int MAX = 700000;
const int MOD = pow(10,9) + 7;
long long fac[MAX], inv[MAX], finv[MAX];

void COMinit(){
  fac[0]=fac[1] = 1;
  inv[1] = 1;
  finv[0] = finv[1] = 1;
  for(int i=2; i<MAX; i++){
    fac[i] = fac[i-1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD/i)%MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
long long COM(int n, int k){
  if(n<k) return 0;
  if(n <0 || k<0) return 0;
  return fac[n]* (finv[n-k]*finv[k] % MOD) % MOD;
}
 
void solve() {
  cin >> X >> Y;
  if((2*X-Y)%3 != 0 || (-X+2*Y)%3 != 0){
    cout << 0 << endl;
  }else{
    int n = (2*X-Y)/3;
    int m = (-X+2*Y)/3;
    COMinit();
    cout << COM(m+n,m) << endl;
  }
  return;
}
 
int main() {
    solve();
    return 0;
}