#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll M = 998244353;


int main() {
  int n;
  cin >> n;
  vector<int> dis(n);
  rep(i,n) {
    int x;  cin >> x;
    if(i==0&&x!=0) {
      cout << 0 << endl;
      return 0;
    } 
    dis[x]++;
  }
  if(dis[0]!=1) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  for(int i=1; i<n; i++) {
    rep(j,dis[i]) {
      ans*=dis[i-1];
      ans%=M;
    }
  }
  cout << ans << endl;
  return 0;
}