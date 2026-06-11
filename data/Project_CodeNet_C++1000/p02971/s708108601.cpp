#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<P> p(n);
  rep(i,n){
    cin >> p[i].first; 
    p[i].second = i+1;
  }
  
  sort(p.rbegin(), p.rend());
  
  rep(i, n){
    if(i+1 == p[0].second){
      cout << p[1].first << endl;
    }
    else
      cout << p[0].first << endl;
  }
}