#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,h,m;cin>>a>>b>>h>>m;
  double pai=acos(-1);
  double hh=(double)(h*60+m)/720*2*pai;
  double mm=(double)m/60*2*pai;
  double x1=a*cos(hh),y1=a*sin(hh);
  double x2=b*cos(mm),y2=b*sin(mm);
  double dx=x1-x2,dy=y1-y2;
  double ans=sqrt(dx*dx+dy*dy);
  cout<<fixed<<setprecision(10)<<ans<<endl;
}