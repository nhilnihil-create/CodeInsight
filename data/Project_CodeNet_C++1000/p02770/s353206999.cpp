//Link : https://atcoder.jp/contests/agc018/tasks/agc018_c

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005

int in[N];
int d[N];
ll solve(int k) {
  ll n,x,m;
  scanf("%lld %lld %lld ", &n,&x,&m);
  ll D = 0;
  ll ret = n-1;
  for(int i=0;i<k;++i) {
    d[i] = in[i]%m;
    D = (D + d[i]);
    if(d[i]==0) {
      if(i+1<=n-1) {
        ll c = (n-1-i-1)/k + 1;
        ret -= c;
      }
    }
  }
  x%=m;
  ll a = x;
  ll b= x + ((n-1)/k)*D;
  int ind = ((n-1)/k)*k + 1;
  while(ind<=n-1) {
    b += d[(ind-1)%k];
    ++ind;
  }
  ret -= b/m;
  ret += a/m;
  return ret;
}
void solve() {
  int k,q;scanf("%d %d ", &k,&q);
  for(int i=0;i<k;++i) {
    scanf("%d ", &in[i]);
  }
  while(q--) {
    printf("%lld\n", solve(k));
  }
}

int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
