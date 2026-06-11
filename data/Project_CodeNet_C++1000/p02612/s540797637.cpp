#include<iostream>
using namespace std;
int main (){
int n,r;
  cin>>n;
  r=n % 1000;
  if(r>0)
  {
    int ans;
    ans=1000-r;
    cout<<ans<<endl;
  }
  else if(r==0)
  {
    cout<<"0"<<endl;
  }
  return 0;
}
  
