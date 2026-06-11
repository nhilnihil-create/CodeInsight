#include<bits/stdc++.h>
using namespace std;
using ll =long long int ;
int main()
{
  ll h,n;
  cin>>h>>n;
  
  while(n--)
  {
    ll x;
    cin>>x;
    h-=x;
    if(h<=0)
    {
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
