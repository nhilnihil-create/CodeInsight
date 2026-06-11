#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,m,sum=0;
  cin>>n>>m;
  vector<int> v(m);
  for(long i=0;i<m;i++)
  {
      cin>>v[i];
  }
  for(long i=0;i<m;i++)
  {
   sum+=v[i];   
  }
  if(n-sum>=0)
  {
      cout<<n-sum<<"\n";
  }
  else
  {
      cout<<"-1"<<"\n";
  }
  return 0;
}