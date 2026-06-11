#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {

  ll H, W; cin >> H >> W;
  ll Hc;
  ll ans;
  if (W == 1 || H == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (H%2==0){
    Hc=H/2;
    ans = Hc * W;
  }else{
    Hc = H/2 + 1;
    ll Hc2 = Hc-1;
    if (W%2 == 0){
      ans = (Hc +Hc2)*W/2;
    }else{
      ll Wc = W/2;
      ans = (Hc + Hc2) * Wc + Hc;
    }
  }
  cout << ans << endl;
}
