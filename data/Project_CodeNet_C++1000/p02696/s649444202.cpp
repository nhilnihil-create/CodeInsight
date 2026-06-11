#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll a,b,n;
  cin>>a>>b>>n;
  ll k=min(b-1,n);
  cout<<(a*k)/b<<endl;
}