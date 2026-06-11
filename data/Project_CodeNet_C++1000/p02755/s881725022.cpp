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

  int a,b;
  cin>>a>>b;
  int  i=1;
  int ans=-1;
  while(true)
  {
    int r1=floor(i*0.08);
    int r2=floor(i*0.1);
    if(r1==a && r2==b)
    {
      ans=i;
      break;
    }
    else if(r1>a || r2>b)
    {
      break;
    }
    i++;
  }

  cout<<ans<<endl;
  return 0;
}