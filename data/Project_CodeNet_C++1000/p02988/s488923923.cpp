#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
  int n,p[20],i,j,k,ans=0;
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>p[i]; 
  }
  for(i=1;i<n-1;i++)
  {
    if(min(p[i-1],p[i+1])<p[i]&&p[i]<max(p[i-1],p[i+1]))
    {
      ans++;
      
    }
  }
  cout<<ans<<endl;
}