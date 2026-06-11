#include <bits/stdc++.h>
using namespace std;
long long INF=1e9+7;
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
#define int long long
signed main(){
  int a,b; cin>>a>>b;
  if((a+b)%3!=0||a*2<b||b*2<a){cout<<0<<endl;return 0;}
  int c=((a+b)/3-(a-b))/2,d=(a+b)/3-c;
  int count=1;
  for(int i=c+d;i>d;i--){
    count*=i;
    count%=INF;
  }
  int A=1;
  for(int i=1;i<=c;i++){
    A*=i;
    A%=INF;
  }
  int B=modinv(A,INF);
  count*=B;
  count%=INF;
  cout<<count<<endl;
}