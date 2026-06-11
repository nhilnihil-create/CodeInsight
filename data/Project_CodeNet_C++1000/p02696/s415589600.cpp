#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll a,b,n;
  cin>>a>>b>>n;
  if(n<b)
  {
    cout<<(a*n)/b<<endl;
  }
  else 
  {
    ll d=n/b;
    d*=b;
    d--;
    cout<<(d*a)/b-(a*(d/b))<<endl;
    
  }
  return 0;
}