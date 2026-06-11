#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,m;
  cin >> n >> m;
  
  vector<ll> hom(m);
  rep(i, m)
    cin >> hom.at(i);
  
  ll date=0;
  rep(i, m)
    date += hom.at(i);
  
  if(n < date)
    cout << -1 << endl;
  else
    cout << n - date << endl;
}