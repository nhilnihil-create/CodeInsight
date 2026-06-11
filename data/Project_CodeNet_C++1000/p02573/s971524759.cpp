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

void dfs(int x,vector<vector<int>> &v,vector<int> &g, int &num){
  int x_size = v[x].size();
  if(x > 0){
    rep(i,x_size){
      if(g[v[x][i]] == 0){
        g[v[x][i]] = num;
        dfs(v[x][i],v,g,num);
      }
    }
  }
}

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> A(M),B(M),group(N+10,0);
  rep(i,M)cin >> A[i] >> B[i];
  vector<vector<int>> G(N+10);
  rep(i,M){
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  int num = 1;
  for(int i = 1;i <= N;i++){
    if(group[i] == 0){
      group[i] = num;
      dfs(i,G,group,num);
      num++;
    }
  }
  vector<int> cnt(N+10,0);
  for(int i = 1;i <= N;i++){
    cnt[group[i]]++;
  }
  int ans = -1;
  for(int i = 1;i <= N;i++){
    if(ans < cnt[i])ans = cnt[i];
  }
  cout << ans << endl;
/*
  for(int i = 1;i <= N;i++){
    cout << group[i] << " ";
  }
  cout << endl;
  for(int i = 1;i <= N;i++){
    cout << G[i].size() << " ";
  }
  cout << endl;
*/
  return 0;
}
