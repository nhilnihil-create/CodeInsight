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
#include <stdio.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;
ll MODP = 998244353;

ll kai(ll x,ll y){
  if(y == 0)return 1;
  if(y == 1)return x;
  if(y&1){
    return (x*kai(x,y-1))%MOD;
  }else{
    ll t = kai(x,y/2);
    return (t*t)%MOD;
  }
}

ll comb(ll a,ll b,vector<ll> &p){
  if(a == 0)return 1;
  if(b == 0)return 1;
  ll ans = p[a+b];
  ans = (ans*kai(p[a],MOD-2))%MOD;
  ans = (ans*kai(p[b],MOD-2))%MOD;
  return ans;
}

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 1;
  char cur = S.at(0);
  for(int i = 1;i < S.size();i++){
    if(S.at(i) != cur){
      ans++;
      cur = S.at(i);
    }else{
      continue;
    }
  }
  cout << ans << endl;




  return 0;
}
