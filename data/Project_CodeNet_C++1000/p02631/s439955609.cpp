#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,x=0;
  cin>>n;
  vector<ll> d(n,0);
  for(ll i=0; i<n; i++){
    cin>>d[i];
    x=x^d[i];
  }
  for(ll i=0; i<n; i++){
    ll a=x^d[i];
    cout<<a<<" ";
  }
    return 0;
}