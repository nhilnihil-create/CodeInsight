
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int n, m;
ll vs[100000+10];
ll ts[100000+10];


ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a%b);
}

inline ll lcm(ll a, ll b) {
  return a/gcd(a,b)*b;
}


ll solve(void) {
  REP(i, n) {
    while(vs[i] % 2 == 0) {
      ts[i]++;
      vs[i] /= 2;
    }
  }
  REP(i, n) {
    if(ts[0] != ts[i]) {
      return 0;
    }
  }
  ll llcm = 1;
  REP(i, ts[0]) {
    llcm *= 2;
  }
  REP(i, n) {
    llcm = lcm(llcm, vs[i]);
    if(llcm > m) {
      return 0;
    }
  }
  return (m / llcm + 1) / 2;
}

int main(void) {
  scanf("%d%d", &n, &m);
  REP(i, n) {
    scanf("%lld", &vs[i]);
    vs[i] /= 2;
  }

  ll res = solve();
  cout << res << endl;
  
  return 0;
}
