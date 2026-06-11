#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i < (int)(n);i++)
typedef long long ll;

#define MODSIZE 1000000007

ll reppow(ll x,ll n){
  ll rep = 1;

  while(n > 0){
    if(n & 1) rep = (rep*x) % MODSIZE;
    x = x*x % MODSIZE;
    n >>= 1;
  }

  return rep;
}

int main(){
  int x;
  int y;
  int n;
  ll a,b;

  scanf("%d %d", &x, &y);

  if((x + y) % 3 != 0){
    printf("0\n");
    return 0;
  }

  n = (x + y)/3;
  x -= n;
  y -= n;

  if(x < 0 || y < 0){
    printf("0\n");
    return 0;
  }

  a = 1; b = 1;

  int i;

  for(i = 0;i < x;i++){
    a = (a*(x + y - i)) % MODSIZE;
    b = (b*(i + 1)) % MODSIZE;
  }

  b = reppow(b,MODSIZE - 2);

  ll ans;

  ans = (a*b) % MODSIZE;

  printf("%lld\n", ans);

  return 0;
}