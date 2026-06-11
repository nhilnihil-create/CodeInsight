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

ll extGCD(ll a, ll  b, ll &x, ll &y){
  if(b==0){
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b,a%b,y,x);
  y -= (a/b)*x;
  return d;
}

ll gen(int c){
  ll res,x,y,hosei;
  hosei = extGCD(MOD,c,x,y);
  res = y;

  if(res<0)res += MOD;
  return res;
}

ll nijou(ll x){
  if(x==1)return 2;
  ll res;
  if(x%2){
    res = 2*nijou(x-1);
  }else{
    res = nijou(x/2)*nijou(x/2);
  }
  return res%MOD;
}

int main() {
  int n,a,b;
  cin >> n >> a >> b;

  ll resa,resb;
  resa = 1;
  resb = 1;
  ll a1,b2,nn;
  nn = n;
  a1 = 1;
  b2 = 1;
  while(nn>=n-a+1 || a1<=a){
    resa = (resa*nn)%MOD;
    resa = (resa*gen(a1))%MOD;
    nn--;
    a1++;
  }
  nn = n;
  while(nn>=n-b+1 || b2<=b){
    resb = (resb*nn)%MOD;
    resb = (resb*gen(b2))%MOD;
    nn--;
    b2++;
  }

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
