#include<iostream>
#include<algorithm>
using namespace std;


int main (void)
{ 
  long long int ans,h,w,x,y;
  
  
  cin>>w>>h>>x>>y;
  ans=h*w/2;
  cout<<ans;
  if(h*w%2==1){cout<<".5";}
  cout<<" ";
 // cout<<w<<" "<<2*x<<" "<<h<<" "<<2*y;
  
  if((w==2*x) && (h==2*y))
  { 
    cout<<"1"<<endl;
    return 0;
  }
  cout<<"0"<<endl;
  return 0;
}
