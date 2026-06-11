#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
vector< ll > z_algorithm(string s) {
  vector< ll > prefix(s.size());
  for(ll i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      ll k = max(0ll, j + prefix[j] - i);
      while(i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (ll) s.size();
  return prefix;
}
int main(){
    ll n; cin>>n;
    string s; cin>>s;
    ll res=0;
    rep(i,n-1){
        vector<ll> tmp=z_algorithm(s);
        ll m=tmp.size();
        for(ll j=1; j<m; j++){
            if(tmp[j]>j) chmax(res, j);
            else chmax(res, tmp[j]);
        }
        ll x=s.size();
        s=s.substr(1, x-1);
    }
    cout<<res<<endl;
    return 0;
}