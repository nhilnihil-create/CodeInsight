#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,i,j,k,s=0,c=1,x=1,t,a;
    cin>>k>>n;
    for(i=1;i<=n;i++)
    {
      cin>>a;
      s+=a;
    }
  if(k-s>=0)
    cout<<k-s;
  else cout<<-1;
}
