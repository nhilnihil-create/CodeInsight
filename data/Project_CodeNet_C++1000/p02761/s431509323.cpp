#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,m;
  cin >> n >> m;
  if(m==0 && n==1){
    cout << 0 << endl;
    return 0;
  }
  vector<bool> ok(n+1,false);
  vi ans(n+1);
  rep(i,m){
    int s,c;
    cin >> s >> c;
    if(s == 1 && c == 0 && n != 1){
      cout << -1 << endl;
      return 0;
    }
    if(ok[s] && ans[s] != c){
      cout << -1 << endl;
      return 0;
    }
    ok[s] = true;
    ans[s] = c;
  }
  for(int i=1; i<=n; i++){
    if(ok[i]) continue;
    if(i == 1) ans[1] = 1;
    else ans[i] = 0;
  }
  rep(i,n) cout << ans[i+1];
}
