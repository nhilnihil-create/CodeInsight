#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,i,sum=0,a;
  cin>>m>>n;
  for(i=1; i<=n; i++)
  {
      cin>>a;
      sum=sum+a;
  }
  if(sum<=m)
  {
      cout<<m-sum;
  }
  else
    cout<<"-1";
}
