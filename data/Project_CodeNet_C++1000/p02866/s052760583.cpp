#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

const ll MOD = 998244353;
ll multip(ll x, ll y) { return (x*y)%MOD; }

int main() {
  int n; scanf("%d", &n);
  vector<int> a(n+1, 0);
  rep(i, n) {
    int x;
    scanf("%d", &x);
    if ((i==0)&&(x!=0)) a[n]++;
    a[x]++;
  }
  if ((a[0]!=1)||(a[n]==1)) {
    printf("0\n");
    return 0;
  }
  while (a[n]==0) n--;
  ll ans=1;
  rep(i, n) {
    rep(j, a[i+1]) ans=multip(ans, a[i]);
  }
  printf("%lld\n", ans);
  return 0;
}