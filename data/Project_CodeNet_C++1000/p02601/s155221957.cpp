#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll a,b,c,k;cin>>a>>b>>c>>k;
  while(k--)
  {
    if(c<=b || c<=a)
    {c=c*2;
    }
    else if(b<=a)
      b*=2;
    else
      c*=2;
  }
  if(c>b && c>a && b>a)
    cout<<"Yes";
  else
    cout<<"No";
}
