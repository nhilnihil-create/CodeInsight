#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(10);
  double a,b,x;cin>>a>>b>>x;
  double pi=3.14159265359;
  double ans;
  if(x/a<=a*b/2) ans=a*b*b/(2*x);
  else ans=2*b/a-2*x/(a*a*a);
  cout<<atan(ans)*180/pi<<endl;
    
 // double l=2*x/(a*b);
 // cout<<l<<endl;
 // double ans=atan2(b,l);
 // cout<<ans*180<<endl;
 // cout<<ans/pi<<endl;
 // cout<<ans*180/pi<<endl;
 // cout<<(ans/pi)*180<<endl;
 // cout<<ans/pi<<endl;
 // cout<<(ans/pi)*180<<endl;
}
