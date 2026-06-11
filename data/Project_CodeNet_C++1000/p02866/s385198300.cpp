#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t powermod(int64_t x, int64_t y, int64_t p){
  if(y < 0 || x <= 0)
    return 0;
  else{
    int64_t n = 1;
    x %= p;
    for(int64_t i = 0; i < y; i++){
      n = n*x%p;
    }
    return n;
  }
}
int main() {
    int64_t mod = 998244353;
    int64_t n;
    cin >> n;
    vector<int>d(n);
    rep(i,n) cin >> d[i];
    if(d[0] != 0) cout << 0 << endl;
    else{
        sort(d.begin(),d.end());
        int dmax = d[d.size()-1];
        vector<int>cnt(dmax+1,0);
        rep(i,n) cnt[d[i]]++;
        int64_t ans = 1;
        if(cnt[0] != 1) cout << 0 << endl;
        else{
            rep(i,dmax) ans = ans*powermod(cnt[i],cnt[i+1],mod)%mod;
            cout << ans << endl;
        }
    }
}