#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  long double a,b,c;
  cin>>a>>b>>c;
  if((c-a-b)>2*sqrt(a*b))
  {
    cout<<"Yes";
  }
  else cout<<"No";
}