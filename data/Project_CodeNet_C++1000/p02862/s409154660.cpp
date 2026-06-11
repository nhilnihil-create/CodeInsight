#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

long long int factmod(long long int a,long long int m) {
    long long int s=1;
    while(a>0){
        s = s*a % m;
        a -= 1;
    }
    return s;
}

int main(){

  long long int x,y;
  cin >> x >> y;

  if((2*x-y)%3!=0 || (2*y-x)%3!=0 || 2*x-y<0 || 2*y-x<0)cout << 0 << endl;
  else{
    long long int a,b;
    a=(2*x-y)/3;
    b=(2*y-x)/3;
    long long int m=1000000007;
    long long int c=factmod(a+b,m);
    c*=modinv(factmod(a,m),m);
    c%=m;
    c*=modinv(factmod(b,m),m);
    c%=m;
    cout << c << endl;
  }

}