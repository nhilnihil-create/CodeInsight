#include<bits/stdc++.h>
using namespace std;


void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  int a[n];
  int b[m];
  long long sum=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    sum+=a[i];
  }
  int j=n-1;
  for(int i=0;i<m;i++)
  {
    cin>>b[i];
    
    
  }
  int ans=0;
  for(int i=0;i<=m;i++)
  {
    while(j>=0&&sum>k)
    {
      sum-=a[j];
      j--;
    }
    if(sum>k)
      break;
    ans=max(ans,i+j+1);
    sum+=b[i];
    
  }

     
     
  
 
 
 
  cout<<ans;
  return;
}


int main()
{
solve();
}

