#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

ll mypow(ll b, ll e) {
  ll o = 1;
  while(e) {
    if(e & 1) o = o * b % MOD;
    e >>= 1;
    b = b * b % MOD;
  }
  return o;
}

int main() {
  int n, d, m = 0;
  ll o = 1;
  scanf("%d", &n);
  vector<int> num(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &d);
    if(!i && d) o = 0;
    m = max(m, d);
    num[d]++;
  }
  if(num[0] != 1) o = 0;
  for(int i = 1; i <= m; i++) { o = o * mypow(num[i - 1], num[i]) % MOD; }
  printf("%lld\n", o);
}