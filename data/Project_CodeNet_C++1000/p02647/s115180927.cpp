#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b))? (a):(b)
#define min(a,b) ((a)<(b))? (a):(b)
int main()
{
  int n,k;
  cin>>n>>k;
  vector<long long>a(n);
  vector<long long>ans(n);
  int f=1,j=0;
  for(int i=0;i<n;i++)cin>>a[i];
  while(j!=k)
  {
    
    f=1;
    vector<int>t(n);
    int count=0;
    for(int i=0;i<n;i++)
    {
      if(i==0)ans[i]=1;
      else ans[i]=count+1;
      if(a[i]>0)
      {
        t[min(i+a[i],n-1)]++;
      	count++;
      }
      
      if(t[i])count-=t[i];
      t[i]=0;
      //cout<<ans[i]<<" ";
    }
    count=0;
    //cout<<endl;
    for(int i=n-1;i>=0;i--)
    {
      if(i!=n-1)ans[i]+=count;
      if(a[i]>0)
      {
        t[max(i-a[i],0)]++;
        count++;
      }
      
      if(t[i])count-=t[i];
      t[i]=0;
      a[i]=ans[i];
      if(a[i]<(n-1))f=0;
      //cout<<ans[i]<<" ";
    }
    j++;
    if(f)break;
  }
  if(j==k)for(int i=0;i<n;i++)cout<<ans[i]<<" ";
  else for(int i=0;i<n;i++)cout<<n<<" ";
  return 0;
}