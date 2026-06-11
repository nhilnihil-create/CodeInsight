#include<iostream>
#include<algorithm>
using namespace std;
main(){
  int w,h,x,y,r,flag=0;
  cin>>w>>h>>x>>y>>r;
  if(x+r>w || x-r<0 || y+r>h || y-r<0)flag=1;
  if(flag==1)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}