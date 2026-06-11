//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define MOD 1000000007

class Comb{
private:
  ll *fac,*finv,*inv;
public:
  Comb(){
    fac = new ll[1000000];
    finv = new ll[1000000];
    inv = new ll[1000000];
    fac[0] = 1;
    for(int i=1;i<1000000;i++){
      fac[i] = i*fac[i-1];
      fac[i] %= MOD;
    }
    inv[1] = 1;
    for(int i=2;i<1000000;i++){
      inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
    }
    finv[0] = 1;
    for(int i=1;i<1000000;i++){
      finv[i] = inv[i]*finv[i-1];
      finv[i] %= MOD;
    }
  }
  ll calc(ll n,ll k){
    ll c = fac[n];
    c *= finv[k];c %= MOD;
    c *= finv[n-k];c %= MOD;
    return c;
  }
};

ll gcd(ll a,ll b){
  if(a%b == 0) return b;
  else return gcd(b,a%b);
}

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 1;
  if(s[0] == 'W' && s[2*n-1] == 'W'){
    ans = 0;
  }
  int opr[2*n];
  opr[0] = 1; //L = 1,R = 0
  for(int i=1;i<2*n;i++){
    if(s[i] == s[i-1]) opr[i] = 1 - opr[i-1];
    else opr[i] = opr[i-1];
  }
  if(opr[2*n-1] == 1) ans = 0;
  ll count[2*n];
  count[0] = 0;
  for(int i=1;i<2*n;i++){
    count[i] = count[i-1];
    if(opr[i-1] == 1) count[i]++;
  }
  if(count[2*n-1] != n) ans = 0;
  ll r = 0;
  for(int i=0;i<2*n;i++){
    if(opr[i] == 1) continue;
    ans *= (count[i]-r);
    ans %= MOD;
    r++;
  }
  for(int i=1;i<n+1;i++){
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
