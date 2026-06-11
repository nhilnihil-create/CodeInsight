#include<bits/stdc++.h>
using namespace std;

int main(){
  int w,h,x,y;
  cin>>w>>h>>x>>y;
  double ans=(double)w*h/2;
  int num=0;
  if(w==x*2&&h==y*2) num++;
  cout<<fixed<<setprecision(15)<<ans<<" "<<num<<endl;
}
