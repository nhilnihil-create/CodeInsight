#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;
const int INF = 1e9;
const int N = 11;

int main() {
  int M, G[N][N];
  while(cin >>M && M){
    int n = 0;
    REP(i, N) REP(j, N) G[i][j] = (i == j ? 0 : INF);
    REP(i, M){
      int f, t, c; cin >>f >>t >>c;
      n = max(n, max(f, t));
      G[f][t] = G[t][f] = min(G[t][f], c);
    }
    ++n;
    REP(k, n) REP(i, n) REP(j, n) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    int index = 0, sum = 0;
    REP(i, n) sum += G[0][i];
    FOR(i, 1, n){
      int _sum = 0;
      REP(j, n) _sum += G[i][j];
      if(_sum < sum){
        index = i;
        sum = _sum;
      }
    }
    cout <<index <<" " <<sum <<endl;
  }
  return 0;
}