#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{

  int a,b,ans;
  cin>>a;
  if(a==1){cout<<"1.000000000"<<endl;}
  else if(a%2==0)cout<<"0.5000000000"<<endl;
  else
  {
    b=a/2+1;
 
    b=b*10000000;
    ans=b/a;
    
    
  
 
   cout<<"0."<<ans;
    
    
  }
}