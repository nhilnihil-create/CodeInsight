#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll k,n;
  cin >> k >> n;
  
  vector<ll> ad(n);
  rep(i, n)
    cin >> ad.at(i);
  
  vector<ll> dist(n);
  rep(i, n-1)
    dist.at(i) = ad.at(i+1) - ad.at(i);
  dist.at(n-1) = ad.at(0) + (k - ad.at(n-1));
    
  sort(dist.begin(),dist.end());
  
  ll sum = 0;
  rep(i, n-1)
    sum += dist.at(i);
  
  cout << sum << endl;
}