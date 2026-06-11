//itp1_2_d

#include <iostream>
using namespace std;

int main(){
 int w,h,x,y,r;
 cin>>w>>h>>x>>y>>r;

 bool inner=false;
 if((x>=r && x<=w-r) && (y>=r && y<=h-r) && (h>=r*2 && w>=r*2))
  inner=true;
 
 if(inner) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;

 return 0;
}