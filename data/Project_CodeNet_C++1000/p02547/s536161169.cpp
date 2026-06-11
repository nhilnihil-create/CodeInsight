#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  bool ok=false;
  int cnt=0;
  while(n--)
  {
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
      cnt++;
    }
    else
    {
      cnt=0;
    }
    if(cnt==3)
    {
      ok=true;
    }
  }
  if(ok)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
  