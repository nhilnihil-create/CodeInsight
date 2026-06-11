#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)
typedef long long ll;

#define MODSIZE 1000000007

ll reppow(ll x,ll n){
  ll res = 1;

  while(n > 0){
    if(n & 1) res = res*x % MODSIZE;
    x = x*x % MODSIZE;
    n >>= 1;
  }

  return res;
}

int main(){
  ll n,k;
  int i,j;
  ll ans;

  scanf("%lld %lld", &n, &k);

  ll t1,t2;
  ll X,Y;

  for(i = 1;i <= k;i++){
    ll r = n - k + 1;
    X = 1; Y = 1;

    for(j = 0;j < i;j++){
      X = X*(r - j) % MODSIZE;
      Y = Y*(j + 1) % MODSIZE;
    }

    Y = reppow(Y,MODSIZE - 2);

    t1 = X*Y % MODSIZE;

    r = k - 1;
    X = 1; Y = 1;
    for(j = 0;j < i - 1;j++){
      X = X*(r - j) % MODSIZE;
      Y = Y*(j + 1) % MODSIZE;
    }

    Y = reppow(Y,MODSIZE - 2);

    t2 = X*Y % MODSIZE;

    ans = t1*t2 % MODSIZE;

    printf("%lld\n", ans);
  }

  return 0;
}