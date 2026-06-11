#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  int n,m;
  cin>>n>>m;
  ll sum=0;
  for(int i=0;i<m;i++)
  {
    int x;
    cin>>x;
    sum+=x;
  }

  if(sum>n)
  {
    cout<<-1<<endl;
  }
  else
  {
    cout<<n-sum<<endl;
  }

  return 0;
}