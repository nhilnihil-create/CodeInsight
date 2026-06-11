#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  long double w,h,x,y;
  cin>>w>>h>>x>>y;
  double kotae=w*h/2;
  ll ans=0;
  if(2*x==w&&2*y==h){
    ans=1;
  }
  cout<<fixed<<setprecision(10)<<kotae<<" "<<ans<<endl;
}