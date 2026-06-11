#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{ 
  int n,x,l[100],i,j,k,ans,a,b;
  cin>>n>>x;
  for(i=0;i<n;i++){cin>>l[i];}
  k=0;
  ans=0;
  if(0<=x){ans++;}
  for(i=0;i<n;i++)
  {
    k=k+l[i];
    if(k<=x){ans++;}
  }
  cout<<ans<<endl;
}