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

vector<int> fac(MX);
vector<int> ifac(MX);

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

int P(int a, int b) {
    int res = comb(a,b);
    res *= fac[b];
    return res % mod;
}

int ans, k;
vector<int> to[100005];
void dfs(int v, int p=-1) {
    for(int u: to[v]) {
        if(u == p) continue;
        dfs(u, v);
    }
    int nk = (p==-1) ? k : k-2;
    int c = (p==-1) ? to[v].size()+1 : to[v].size()-1;
    ans *= P(nk, c);
    ans %= mod;
}

signed main(){
    int n;
    cin >> n >> k;

    for (size_t i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a>>b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    fac[0] = 1;
    ifac[0] = 1;
    for(int i = 0; i<MX-1; i++){
        fac[i+1] = fac[i]*(i+1) % mod; // n!(mod M)
        ifac[i+1] = ifac[i]*fpow(i+1,mod-2) % mod; 
    }
    ans = 1;
    dfs(0);
    cout << ans << endl;
    return 0;
}


