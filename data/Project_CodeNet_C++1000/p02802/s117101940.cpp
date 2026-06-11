#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,m; cin >> n >> m;
  vector<bool> AC(n,true); vector<ll> WA(n,0);
  ll a = 0; ll w = 0;
  
  rep(i, m){
    ll p; string s; 
    cin >> p >> s;
    
    if(AC[p-1] && s == "AC"){
      AC[p-1] = false;
      a++;
      w += WA[p-1];
    }
    if(s == "WA"){
      WA[p-1]++;
    }
  }
  cout << a << " " << w << endl;
}