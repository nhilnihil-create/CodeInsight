#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  const int mod = 2019;
  int l, r;
  cin >> l >> r;

  int ans = 2018;
  REP(i,l,r+1)REP(j,i+1,r+1){
    if (ans == 0){
      cout << ans << endl;
      return 0;
    }
    int x = (ll)i * j % mod;
    ans = min(ans, x);
  }
  cout << ans << endl;
  return 0;
}
