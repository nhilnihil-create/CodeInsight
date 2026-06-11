#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,m; cin >> n >> m;
  vector<ll> h(n);
  rep(i, n)
    cin >> h[i];
  
  vector<bool> l(n, true);
  ll cnt = 0;
  rep(i, m){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    
    if(h[a] < h[b]){
      if(l[a] == true){
        l[a] = false;
        cnt++;
      }
    }
    
    else if(h[a] > h[b]){
      if(l[b] == true){
        l[b] = false;
        cnt++;
      }
    }
    
    else{
      if(l[a] == true){
        l[a] = false;
        cnt++;
      }
      if(l[b] == true){
        l[b] = false;
        cnt++;
      }
    }
  }
  
  cout << n - cnt << endl;
}