#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  struct Edge{ll l,r,level;};

  std::queue<Edge> que;

  std::vector<std::vector<ll>> level(n,std::vector<ll>(n,0));

  que.push(Edge{0,n-1,1});

  while(que.size()){
    Edge e=que.front();que.pop();

    ll num=(e.r-e.l+1)/2;
    rep(i,e.l,e.l+num){
      rep(j,e.l+num,e.r+1){
        level[i][j]=e.level;
      }
    }

    if(e.l!=e.l+num-1)que.push(Edge{e.l,e.l+num-1,e.level+1});

    if(e.l+num!=e.r)que.push(Edge{e.l+num,e.r,e.level+1});
  }

  rep(i,0,n){
    rep(j,i+1,n){
      std::cout<<level[i][j];
      if(j!=n-1)std::cout<<" ";
    }
    std::cout<<"\n";
  }

  return 0;
}