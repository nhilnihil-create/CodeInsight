#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
using namespace std;
int main(){
 long double a,b,h,m;
  long double ans,c,dis;
  long double pi=3.141592653589793;
  cin>>a>>b>>h>>m;
  dis=abs(h*30+m/2-6*m);//角度は正になるように
  c=cos(dis*pi/180);//cosC
  ans=sqrt(a*a+b*b-2*a*b*c);
  cout<<fixed<<setprecision(10)<<ans<<endl;//fixed で小数点以下だよと教えてあげる。 setprecision で小数点以下の長さを指定してあげる。
}
  