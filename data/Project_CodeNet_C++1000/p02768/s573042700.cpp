//g++ -std=gnu++14 a.cpp
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;

ll gen(ll x, ll y){
  if(y == 1)return x;
  if(y%2)return (x*gen(x,y-1))%MOD;
  ll res = (gen(x,y/2))%MOD;
  return (res*res)%MOD;
}

ll nijou(ll x){
  if(x==1)return 2;
  if(x%2)return (2*nijou(x-1))%MOD;
  ll res = nijou(x/2)%MOD;
  return (res*res)%MOD;
}

ll kaijou(ll x){
  ll res = 1;
  while(x>0){
    res *= x;
    x--;
    res %= MOD;
  }
  return res%MOD;
}

int main() {
  int n,a,b;
  cin >> n >> a >> b;

  ll resa,resb;
  resa = 1;
  resb = 1;
  ll nn;
  nn = n;
  while(nn>=n-a+1){
    resa = (resa*nn)%MOD;
    nn--;
  }
  resa *= gen(kaijou(a),MOD-2);
  resa %= MOD;
  nn = n;
  while(nn>=n-b+1){
    resb = (resb*nn)%MOD;
    nn--;
  }
  resb *= gen(kaijou(b),MOD-2);
  resb %= MOD;

  ll all = nijou(n);
  //cout << all << endl;
  ll ans = all-resa-resb-1;
  ans %= MOD;
  if(ans < 0)ans += MOD;
  //if(ans < 0) ans += MOD;
  //cout <<  resa << " " << resb << endl;
  //cout  << nijou << endl;
  cout << ans << endl;
}
