#include<bits/stdc++.h>
using namespace std;

int main()
{
  int l,r,d;
  cin>>l>>r>>d;

 int ans=(r/d)-(l/d);
  if(l%d==0)
    ans++;
  cout<<ans;
}

