#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,i,k,m,x,y,ans=0;
  cin>>n>>k;
  priority_queue<int>qu;
  for(i=0;i<n;i++)
  {
    cin>>x;
    qu.push(x);
  }
  for(i=0;i<k;i++)
  {
    x=qu.top();
    qu.pop();
    qu.push(x/2);
  }
  for(i=0;i<n;i++)
    {
      ans+=qu.top();
      qu.pop();
    }
    cout<<ans<<endl;
}