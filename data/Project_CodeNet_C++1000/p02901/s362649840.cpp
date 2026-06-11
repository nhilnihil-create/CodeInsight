#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>a(m);
  vector<int>b(m);
  for(int i=0;i<m;i++)
  {
    int B;
    cin>>a[i]>>B;
    for(int j=0;j<B;j++)
    {
      int t;
      cin>>t;
      b[i]|=(1<<(t-1));
    }
  }
  //for(int i=0;i<m;i++)cout<<b[i]<<endl;
  vector<int>d(1<<n,1000000000);
  d[0]=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<(1<<n);j++)
    {
      if(d[j|b[i]]>(d[j]+a[i]))
        d[j|b[i]]=d[j]+a[i];
    }
  }
  if(d[(1<<n)-1]==1000000000)cout<<-1<<endl;
  else cout<<d[(1<<n)-1]<<endl;
                        
  return 0;
 }
   
    