#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
  ll n;
  cin >> n;
  vector<pair<ll,ll>> k;
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    k.push_back(make_pair(a+b,a-b));
  }
  sort(k.begin(),k.end());
  ll ans=1;
  pair<ll,ll> p=k[0];
  ll r=p.first;
  rep(i,n-1){
    int y=i+1;
    if(k[y].second<r)continue;
    ans++;
    r=k[y].first;
  }
  cout << ans << endl;
}
