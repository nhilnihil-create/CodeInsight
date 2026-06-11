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
  int x1=ceil(a/0.08);
  int x2=ceil(b/0.1);
  int x=max(x1,x2);
  if(floor(x*0.08)==a && floor(x*0.1)==b)
  {
    cout<<x<<endl;
  }
  else
    cout<<-1<<endl;

  return 0;
}