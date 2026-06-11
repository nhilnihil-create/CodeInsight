#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll n;
  ll count=0;
  cin>>n;
  bool check=false;
  while(n--)
  {
    ll x,y;
    cin>>x>>y;
    if(x==y)
      count++;
    else
      count=0;
    
    if(count==3)
      check=true;
  }
  
  if(check)
    cout<<"Yes";
  else
    cout<<"No";  
  
}