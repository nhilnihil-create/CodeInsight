#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,k,R,S,P;
  string t;
  cin >> n >> k >> R >> S >> P >> t;
  int ans = 0;
  vector<bool>po(n,false);
  rep(i,0,k){
    if(t[i] == 'r') ans += P;
    if(t[i] == 's') ans += R;
    if(t[i] == 'p') ans += S;
    po[i] = true;
  }
  rep(i,k,n){
    if(po[i-k] && t[i] == t[i-k]) continue;
    if(t[i] == 'r') ans += P;
    if(t[i] == 's') ans += R;
    if(t[i] == 'p') ans += S;
    po[i] = true;
  }
  cout << ans << endl;
}