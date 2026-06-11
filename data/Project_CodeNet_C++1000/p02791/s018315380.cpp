#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> p(n); rep(i,n) cin >> p[i];

  vector<int> m(n,-1);
  m[0] = p[0];
  for(int i = 1;i<n;i++){
    m[i] = min(p[i-1],m[i-1]);
    //cout << i << " " << p[i] << " " << m[i] << endl;
  }
  
  ll ans = 0;
  rep(i,n){
    if(p[i]<=m[i]) ans++;
  }

  cout << ans << endl;
  
  return 0;
}
