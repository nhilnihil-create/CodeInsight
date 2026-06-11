#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,h,m;cin>>a>>b>>h>>m;
  double pai=acos(-1);
  double hh=(double)(m+h*60)/720*2*pai;
  double mm=(double)m/60*2*pai;
  double xh=a*cos(hh),yh=a*sin(hh);
  double xm=b*cos(mm),ym=b*sin(mm);
  double dx=xh-xm,dy=yh-ym;
  double ans=sqrt(dx*dx+dy*dy);
  cout<<fixed<<setprecision(10)<<ans<<endl;
}