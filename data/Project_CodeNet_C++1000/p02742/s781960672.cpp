#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll h,w;
  cin>>h>>w;
  if(h!=1&&w!=1)
  {
    cout<<(h*w+1)/2<<endl;
    return 0;
  }
  cout<<1;
}