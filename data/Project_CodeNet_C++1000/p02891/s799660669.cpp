#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;


int main(){
  string s;
  ll k;
  cin >> s >> k;
  ll n = sz(s);
  vector<ll> seq(0);

  ll cnt = 1;
  rep(i,n){
    if(i == n-1) {
      seq.push_back(cnt);
      continue;
    }
    if(s[i] == s[i+1]) cnt++;
    else{
      seq.push_back(cnt);
      cnt = 1;
    }

  }

  ll ns = seq.size();

  ll ans = 0;
  if(s[0] != s[n-1]){
    for(auto s : seq){
      ans += s/2;
    }
    ans *= k;
  }

  else if(ns == 1){
    ans = seq[0]*k;
    ans /= 2;
  }

  else {
    for(int i = 0; i < ns; i++){
      if(i == 0 || i == ns-1) continue;
      ans += seq[i]/2;
    }
    ans *= k;
    ans += seq[0]/2 + seq.back()/2;
    int add = (seq[0]+seq.back())/2;
    ans += add*(k-1);
  }

  cout << ans << endl;
  
}
