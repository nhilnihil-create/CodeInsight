#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i < (int)(n);i++)
typedef long long ll;

#define MODSIZE 1000000007

ll reppow(ll x,ll n){
  ll res = 1;
  while(n > 0){
    if(n & 1) res = (res*x) % MODSIZE;
    x = (x*x) % MODSIZE;
    n >>= 1;
  }

  return res;
}

ll mod(ll val,ll m){
  ll res = val % m;
  if(res < 0) res += m;

  return res;
}

int main(){
  ll n,a,b;
  ll Xa,Xb;
  ll Ya,Yb;
  ll Z;
  ll ans;

  scanf("%lld %lld %lld", &n, &a, &b);

  int i;

  Xa = 1; Xb = 1; Ya = 1; Yb = 1;
  for(i = 0;i < a;i++){
    Xa = (Xa*(n - i)) % MODSIZE;
    Ya = (Ya*(i + 1)) % MODSIZE;
  }

  for(i = 0;i < b;i++){
    Xb = (Xb*(n - i)) % MODSIZE;
    Yb = (Yb*(i + 1)) % MODSIZE;
  }

  Ya = (reppow(Ya,MODSIZE - 2));
  Yb = (reppow(Yb,MODSIZE - 2));

  Z = mod((reppow(2,n) - 1) % MODSIZE - Xa*Ya % MODSIZE,MODSIZE);
  ans = mod(Z - Xb*Yb % MODSIZE,MODSIZE);

  printf("%lld", ans);

  return 0;
}