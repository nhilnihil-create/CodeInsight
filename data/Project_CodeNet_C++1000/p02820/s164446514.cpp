#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n,k,r,s,p;
  cin >> n >> k >> r >> s >> p;
  string S; cin >> S;
  ll ans = 0;
  vector<bool> skip(n,false);
  
  rep(i,n){
    
    if(i < k){ //「k個前」を考えなくてよいとき
      if(S[i] == 'r') ans += p;
      if(S[i] == 's') ans += r;
      if(S[i] == 'p') ans += s;
    }
    
    else{ //「k個前」を考えないといけないとき
      if(S[i] != S[i-k]){ //不一致なら素直に足してよい
        if(S[i] == 'r') ans += p;
        if(S[i] == 's') ans += r;
        if(S[i] == 'p') ans += s;
      }
      else{ //一致なら、すでに飛ばしたかを検討
        if(skip[i-k] == false) skip[i] = true;
        else{
          if(S[i] == 'r') ans += p;
          if(S[i] == 's') ans += r;
          if(S[i] == 'p') ans += s;
        }
      }
    }
    
  }
   
  cout << ans << endl;
}