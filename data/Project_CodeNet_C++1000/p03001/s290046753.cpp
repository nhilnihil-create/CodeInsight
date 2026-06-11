#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
  ll w,h,x,y;cin>>w>>h>>x>>y;
  bool ans=0;
  if(w==2*x&&h==2*y)ans=1;
  cout<<fixed<<setprecision(15)<<(double)w*h/2<<" ";
  cout<<ans<<endl;
}