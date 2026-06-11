#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >> k;
  ll a[n+1]={};
  for(ll i=0;i<n;i++)cin >> a[i+1];

  ll s[n+1]={};
  for(ll i=0;i<n;i++)s[i+1]=s[i]+a[i+1];

  vector<pair<ll,ll>> v;
  for(ll i=0;i<=n;i++)v.push_back(make_pair(((s[i]-i)%k+k)%k,i));

  sort(v.begin(),v.end());

  ll c=0;

  for(ll i=0;i<=n;i++){
    ll p=lower_bound(v.begin(),v.end(),make_pair(v[i].first,v[i].second))-lower_bound(v.begin(),v.end(),make_pair(v[i].first,v[i].second-k+1));
    c+=p;
  }

  cout << c << endl;

  //for(ll i=0;i<n;i++)cout << v[i].first << " " << v[i].second << endl;


}