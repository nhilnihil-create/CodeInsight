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

ll mind(int x,vector<int> &v){
  int ok = v.size()-1,ng = -1;
  while(ok - ng > 1){
    int next = (ok+ng)/2;
    if(v[next] > x){
      ok = next;
    }else{
      ng = next;
    }
  }
  return ok;
}

ll maxd(int x,vector<int> &v){
  int ok = 0,ng = v.size();
  while(ng - ok > 1){
    int next = (ok+ng)/2;
    if(v[next] < x){
      ok = next;
    }else{
      ng = next;
    }
  }
  return ok;
}

int main(){
  ll N,K;
  cin >> N >> K;
  vector<ll> P(N+1),C(N+1);
  for(int i = 1;i <= N;i++)cin >> P[i];
  for(int i = 1;i <= N;i++)cin >> C[i];
  vector<vector<ll>> score(N+10,vector<ll> (N+10,0));
  vector<vector<ll>> count(2,vector<ll> (N+1,0));
  for(int i = 1;i <= N;i++){
    ll cur = i;
    for(int j = 1;j <= N;j++){
      score[j][i] = score[j-1][i] + C[P[cur]];
      cur = P[cur];
      if(cur == i){
        count[0][i] = j;
        count[1][i] = score[j][i];
      }
    }
  }
/*
  rep(i,N+1){
    rep(j,N+1){
      cout << score[i][j] << " ";
    }
    cout << endl;
  }
  */

  ll ans = (-1)*INFL;
  for(int i = 1;i <= N;i++){
    for(int j = 1;j <= N;j++){
      ll a = count[0][j],b = count[1][j];
      if(i > a)continue;
      if(i > K)continue;
      ll res = score[i][j];
      if(b > 0)res += ((K-i)/a)*b;
      if(res > ans){
        ans = res;
        a = i;
        b = j;
      }
    }
  }
  //cout << ans << " " << a << " " << b << endl;
  cout << ans << endl;

  return 0;
}
