#include<bits/stdc++.h>
#define ll long long int
#define FOR(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n)
 
using namespace std;

static const int MAX = 100;
static const int INFTY = (1<<21);
static const int white =0;
static const int gray = 1;
static const int black = 2;

int n, M[MAX][MAX];

int dijkstra() {
  int u, minv;
  int d[MAX], color[MAX];

  REP(i, n) {
    d[i] = INFTY;
    color[i] = white;
  }

  d[0] = 0;
  color[0] = gray;

  while( 1 ) {
    minv = INFTY;
    u = -1;
    REP(i, n) {
      if (minv > d[i] && color[i] != black ) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1) break;
    color[u] = black;
    REP(v, n) {
      if (color[v] != black && M[u][v] != INFTY) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          color[v] = gray;
        }
      }
    }
  }
  REP(i, n) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  cin >> n;
  REP(i, n) {
    REP(j, n) {
      M[i][j] = INFTY;
    }
  }

  int k, c, u, v;
  REP(i, n) {
    cin >> u >> k;
    REP(j, k) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  dijkstra();
  return 0;
}