#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

vector<int> fac(300001); //n!(mod M)
vector<int> ifac(300001); //k!^{M-2} (mod M)

long long fpow(long long a,long long n){
  long long ret=1;
  if(n==1) return a;
  if(n%2==0) {
      ret = fpow(a*a%mod, n/2) %mod ;
  }else {
      ret = (a%mod)*fpow(a*a%mod, n/2) %mod;
  }
  return ret %mod;
}
int comb(int a, int b){ //aCbをmod計算
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    int tmp = ifac[a-b]* ifac[b] % mod;
    return tmp * fac[a] % mod;
}
const int D = 60;
int to[D][MX];


signed main(){
    int n,m;
    cin >> n >> m;
    vector<int> a, c;
    vector<int> dp(5000, inf);
    dp[0] = 0;
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        int num=0;
        rep(j,y) {
            int k;
            cin >> k;

            k--;
            num |= 1<<k;
        }
        c.push_back(num);
    }


    rep(j,1<<n) {
        if(dp[j]==inf) continue;
        rep(i,m) {
            dp[j|c[i]] = min(dp[j] + a[i], dp[j|c[i]]);
        } 
    }
    if(dp[(1<<n)-1]==inf) cout << -1 << endl;
    else cout<<dp[(1<<n) - 1] << endl;

    return 0;
}