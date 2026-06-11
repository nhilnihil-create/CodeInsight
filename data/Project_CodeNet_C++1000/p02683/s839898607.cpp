#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,x;
  cin>>n>>m>>x;
  vector<vector<int>>a(n,vector<int>(m));
  vector<int>c(n);
  
  for(int i=0;i<n;i++)
  {
    cin>>c[i];
    for(int j=0;j<m;j++)
      cin>>a[i][j];
    
    
  }
  int all=1<<n;
  int ans=INT_MAX;
  for(int mask=0;mask<all;mask++)
  {
      vector<int>level(m);
       int cost=0;
   for(int i=0;i<n;i++)
   { 
       
      if(mask>>i&1)
      {
        cost+=c[i];
        for(int j=0;j<m;j++)
        {  
          level[j]+=a[i][j];
        }
        
      }
   
   }
    bool ok=true;
      for(int k=0;k<m;k++)
      {
        if(level[k]<x)
          ok=false;
      }
      if(ok)
        ans=min(ans,cost);
     
    
  }
  if(ans==INT_MAX)
    cout<<-1<<endl;
  else
cout<<ans<<endl;
      
 }

int main()
{
solve();
}
