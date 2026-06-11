#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  string s,t;
  cin >> s >> t;
  ll cnt = 0;
  
  if(s.at(0) == t.at(0))
    cnt++;
  if(s.at(1) == t.at(1))
    cnt++;
  if(s.at(2) == t.at(2))
    cnt++;
  
  cout << cnt << endl;
}