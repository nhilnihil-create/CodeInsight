#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n,a,b;
  cin>>n>>a>>b;
  if(abs(a-b)%2==0)
  {
    cout<<abs(a-b)/2<<endl;
  }
  else
  {
    if(abs(a-1)<abs(b-n))
    {
      cout<<abs(a-1)+1+
      abs(b-a-1)/2<<endl;
    }
    else
    {
      cout<<abs(b-n)+1+
      abs(b-a-1)/2<<endl;
    }
  }
}