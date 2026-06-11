#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  set<string> S;
    
  rep(i, n){
    string s; cin >> s;
    S.insert(s);
  }
  
  cout << S.size() << endl;
}