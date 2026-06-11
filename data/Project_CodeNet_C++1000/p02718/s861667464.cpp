#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,m,sum,line,ans;
  ans=1;
  sum=0;
  cin>>n>>m;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
    sum+=a.at(i);
  }
  if(sum%(m*4)==0)
    line=sum/(m*4)-1;
  else
    line=sum/(m*4);
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(int i=0;i<m;i++)
  {
    if(a.at(i)<=line)
    {
      ans=0;
      break;
    }
  }
  if(ans==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}