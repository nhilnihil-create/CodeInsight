#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,h,m;cin>>a>>b>>h>>m;
  double pi=acos(-1);
  double th=(double)(h*60+m)/720*2*pi;
  double tm=(double)m/60*2*pi;
  double x1=a*cos(th),y1=a*sin(th);
  double x2=b*cos(tm),y2=b*sin(tm);
  double dx=x1-x2,dy=y1-y2;
  double ans=sqrt(dx*dx+dy*dy);
  cout<<fixed<<setprecision(10)<<ans<<endl;
}