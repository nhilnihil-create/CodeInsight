#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll n;
  cin>>n;
  
  ll c=0;
  ll i;
  for(i=1;i*i<n;i++)
  {
    if(n%i==0)
      c+=(n/i-i);
    else
      c+=(n/i-i+1);
  }
  i--;
  c*=2;
  cout<<c-i;
  
}
    