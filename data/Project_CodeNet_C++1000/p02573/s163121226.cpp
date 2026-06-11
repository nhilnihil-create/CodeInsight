#include <map>
#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;

template<class T> bool chmin(T &a, T b) { return a>b?(a=b,true):false; }
template<class T> bool chmax(T &a,T  b) { return a<b?(a=b,true):false; }
#define forn(i,x,y) for(int i=(x);i<(int)(y);i++)
#define rep(i,y) for(int i=0;i<(int)(y);i++)
#define repb(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)

const int MAX_N = 200020;
int par[MAX_N]; // 親
int rank2[MAX_N]; // 木の深さ

// n要素で初期化
void init(int n) {
  for (int i=0; i<n; i++) {
    par[i] = i;
    rank2[i] = 0;
  }
}

// 木の根を求める
int find(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = find(par[x]);
}

// xとyの属する集合を併合
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rank2[x] < rank2[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank2[x] == rank2[y]) rank2[x]++;
  }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y) {
  return find(x) == find(y);
}

int n,m;
int cnt[200020];
int main() {
    cin >> n >> m;
    init(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        unite(a,b);
    }
    int mx = 0;
    rep(i,n) {
        int gr = find(i);
        cnt[gr]++;
        chmax(mx, cnt[gr]);
    }
    cout << mx << endl;
}