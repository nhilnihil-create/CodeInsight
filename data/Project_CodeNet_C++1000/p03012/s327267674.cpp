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
const int inf = 1e9+5;
const int mod = 998244353;

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
const double PI=3.14159265358979323846;
int dp[100][100];
int tmp[100][100];
signed main(){
    int n;
    cin >> n;
    int w[n];
    rep(i, n) {
        cin >> w[i];
    }
    int a = 0;
    int b = 0;
    int ans = MX;
    rep(i,n) {
        a = 0;
        b = 0;
        rep(j, n) {
            if(j<=i) a+=w[j];
            else b+=w[j];
        }
        ans = min(abs(a-b), ans);
    }



    cout << ans << endl;

    return 0;

}
