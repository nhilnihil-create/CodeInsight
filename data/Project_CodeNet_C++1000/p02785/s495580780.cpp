#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,k;
  cin >> n >> k;
  
  vector<ll> hp(n);
  rep(i, n)
    cin >> hp.at(i);
  sort(hp.begin(),hp.end());
  
  ll sum = 0;
  rep(i, n-k)
    sum += hp.at(i);
  
  cout << sum << endl;
}
