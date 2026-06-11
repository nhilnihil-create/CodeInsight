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

signed main(){
    int n, a, b ;
    cin >> n >> a >> b;
    int ans = fpow(2,n) - 1;
    //大した量ではないので，先にfax[i]とifax[i]を全て計算しておく
    fac[0] = 1;
    ifac[0] = 1;
    for(int i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
        ifac[i+1] = ifac[i]*fpow(i+1,mod-2) % mod; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }

    int ia = 1;
    for (size_t i = 0; i < a; i++)
    {
        ia *= n-i;
        ia %= mod;
    }
    
    int ib = 1;
    for (size_t i = 0; i < b; i++)
    {
        ib *= n-i;
        ib %= mod;
    }
    // cout << ia <<" "<< ia*ifac[a]%mod << endl;
    // cout << ib << " " <<ifac[b] << " " <<ib*ifac[b]%mod << endl;

    ans = ans - ia*ifac[a]%mod - ib*ifac[b]%mod;
    while(ans<0) ans += mod;
    cout << ans << endl;
    
}