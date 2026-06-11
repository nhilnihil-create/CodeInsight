#include<bits/stdc++.h>
using namespace std;
static const double pi=3.14159265358979;
int main(){
double a,b,x;
  cin>>a>>b>>x;
  if((a*a*b)/2<=x){
  double ans=atan((2*(a*a*b-x))/(a*a*a));
  ans*=(180/pi);
  cout<<fixed<<setprecision(10)<<ans<<endl;
  }else{
  double ans=atan((a*b*b)/(2*x));
    ans*=(180/pi);
    cout<<fixed<<setprecision(10)<<ans<<endl;
  }
  return 0;
}