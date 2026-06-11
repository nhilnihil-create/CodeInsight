#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  ll n;
  cin >> n;
  vector<long long> c(n);
  rep(i,n){
    char s;
    cin >> s;
    if(s == 'R'){
      c[i] = 1;
    }
    else{
      c[i] = 0;
    }
  }
  ll r = 0;
  ll w = 0;
  rep(i,n){
    if(c[i] == 1){
      r++;
    }
  }
  rep(i,n){
    if(c[i] == 0){
      w++;
    }
  }
  
  ll R = r;
  ll W = 0;
  ll ans = max(R,W);
  
  rep(i,n){
    if(c[i] == 1){
      R = R-1;
    }
    if(c[i] == 0){
      W = W+1;
    }
    ans = min(ans,max(R,W));
  }
  cout << ans;
  return 0;
}