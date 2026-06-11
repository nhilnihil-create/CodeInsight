#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n;
  cin>>n;
  vector<ll> a(n);
  ll sum=0;
  for(auto&& e: a) 
  {
    cin>>e;
    sum+=e;
  }
  vector<ll> cost(n-1);
  ll left=0;
  for (int i = 0; i < n-1; ++i)
  {
    left+=a[i];
    cost[i]=abs(sum-left-left);
  }
  cout<<*min_element(cost.begin(), cost.end())<<endl;
}