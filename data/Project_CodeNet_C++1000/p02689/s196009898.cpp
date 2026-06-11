#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
  ll n,m,ans=0;
  cin >> n >> m;
  vector<ll> h(n+10),a(m),b(m),check(n+10,1);
  rep(i,n){
    cin >> h.at(i+1);
  }
  rep(i,m){
    cin >> a.at(i) >> b.at(i);
  }
  
  rep(i,m){
    if(h.at(a.at(i)) <= h.at(b.at(i))){
      check.at(a.at(i)) = 0;
    }
    if(h.at(a.at(i)) >= h.at(b.at(i))){
      check.at(b.at(i)) = 0;
    }
  }
  
  rep(i,n){
    if(check.at(i+1) == 1){
      ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
