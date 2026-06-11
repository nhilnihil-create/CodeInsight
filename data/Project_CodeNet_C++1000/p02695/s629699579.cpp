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

ll N,M,Q;
vector<ll> A,B,C,D;
ll ans;

void dfs(vector<ll> num, vector<ll> A,vector<ll> B,vector<ll> C,vector<ll> D){
  if(num.size() == N+1){
    ll add = 0;
    rep(i,Q){
      if(num[B[i]] - num[A[i]] == C[i])add += D[i];
    }
    if(ans < add)ans = add;
    return;
  }
  num.push_back(num.back());
  while(num.back() <= M){
    dfs(num,A,B,C,D);
    num.back()++;
  }
}



int main(){
  cin >> N >> M >> Q;
  vector<ll> A(Q),B(Q),C(Q),D(Q);
  rep(i,Q)cin >> A[i] >> B[i] >> C[i] >> D[i];
  ans = 0;
  vector<ll> num(1,1);
  dfs(num,A,B,C,D);
  cout << ans << endl;


  return 0;
}
