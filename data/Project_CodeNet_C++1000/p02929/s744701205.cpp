#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

const lint mod = 1e9 + 7;

lint powmod(long x, long n){
  lint ret = 1;
  while(n > 0){
    if(n&1) ret *= x, ret %= mod, n -= 1;
    else x *= x, x %= mod, n >>= 1;
  }
  return ret;
}

vector<lint> fact;
vector<lint> revfact;

void setfact(int n){
  fact.resize(n+1); revfact.resize(n+1);
  fact[0] = 1;
  rep(i, n) fact[i+1] = fact[i] * (i+1) % mod;
  
  revfact[n] = powmod(fact[n], mod-2);
  for(int i=n-1; i>=0; i--) revfact[i] = revfact[i+1] * (i+1) % mod;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    if(s[0] == 'W' || s[2*n-1] == 'W'){
        printf("0\n");
        return 0;
    }
    int ed[2*n];
    ed[0] = 0;
    int cnt = 0;
    rep(i, 2*n-1){
        ed[i+1] = ed[i] ^ (s[i] == s[i+1]);
        cnt += ed[i+1];
    }
    if(cnt != n){
        printf("0\n");
        return 0;
    }
    setfact(n);
    lint ans = fact[n];
    lint cur = 0;
    rep(i, 2*n){
        if(ed[i]) ans = ans * (cur--) % mod;
        else ++cur;
    }
    printf("%lld\n", ans);
}