#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n;
  string s;
  cin >> n >> s;
  
  ll cnt = 0;
  
  rep(i, n-2){
    if(s.at(i)=='A' && s.at(i+1)=='B' && s.at(i+2)=='C')
      cnt++;
  }
  cout << cnt << endl;
}