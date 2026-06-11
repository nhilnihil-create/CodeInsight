#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  ll a,b,x; cin>>a>>b>>x;
  if(2*x<=a*a*b) {cout<<fixed<<setprecision(15)<<atan((double)(a*b*b)/(2*x))*180/pi<<endl; return 0;}
  x=a*a*b-x; 
  cout<<fixed<<setprecision(15)<<atan((double)(2*x)/(a*a*a))*180/pi<<endl;
  return 0;
}
