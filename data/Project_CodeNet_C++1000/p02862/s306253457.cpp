#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;
const long long Mo=1000000007;
         

long long gcn(long long x,long long y){
  if(x%y==0){  
    return y;    
  }
  else{
    return gcn(y,x%y);
  }
}

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

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

int main(void){
  long long tmp,tmp1,tmp2;
  long long x,y,xx,yy;
  long long i,j;
  long long res=0;

  cin>>x>>y;
  tmp=x+y;
  if(tmp%3!=0 || max(x,y)>2*min(x,y)){
    cout<<res<<endl;
    return 0;
  }
  
  tmp=tmp/3;
  x=x-tmp;
  y=y-tmp;
  
  xx=min(x,y);
  yy=max(x,y);
  
  //cout<<xx<<" "<<yy<<endl;
  tmp=1;
  res=1;
  for(i=yy+1;i<=x+y;i++){
    res=res*i%Mo;
  }
  for(i=1;i<=xx;i++){
    tmp=tmp*i%Mo;
  }

  //cout<<res<<" "<<tmp<<" "<<modinv(tmp,Mo)<<endl;
  res=res*modinv(tmp,Mo)%Mo;
  
  //cout<<setprecision(15)<<res<<endl;
  cout<<res<<endl;

  
  return 0;
}