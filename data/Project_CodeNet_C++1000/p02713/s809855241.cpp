#include<bits/stdc++.h>
using namespace std;

int gcm(int x,int y)
{
  if(x%y==0)
    return y;
  return gcm(y,x%y);
}

int main()
{
  int n,ans;
  ans=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(int k=1;k<=n;k++)
      {
        ans+=gcm(gcm(i,j),k);
      }
    }
  }
  cout<<ans<<endl;
}