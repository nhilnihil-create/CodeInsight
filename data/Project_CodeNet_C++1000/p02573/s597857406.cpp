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

struct Unionfind {
  vector<int> d;
  Unionfind(int n): d(n,-1) {} //dを初期化
  int find(int x){
    if(d[x] < 0)return x;
    return find(d[x]);
  }
  bool unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return false;
    if(d[x] > d[y]) swap(x,y);//小さい方を大きい方にくっつける
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x,int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};


int main(){
  int N,M;
  cin >> N >> M;
  Unionfind uf(N);
  rep(i,M){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a,b);
  }
  int ans = 0;
  rep(i,N){
    if(ans < uf.size(i))ans = uf.size(i);
  }
  cout << ans << endl;
  return 0;
}
