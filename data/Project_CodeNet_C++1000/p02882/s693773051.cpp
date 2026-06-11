#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  double a,b,x;
  cin>>a>>b>>x;
  double s=x/a;
  double deg=0;
  if(s>=a*b/2){
    double h=2*(a*b-s)/a;
    deg=atan2(h,a);
  }
  else{
    double w=2*s/b;
    deg=atan2(b,w);
  }
  double ans=deg/acos(-1)*180;
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;                       
}