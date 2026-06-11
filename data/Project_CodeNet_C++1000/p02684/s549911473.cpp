// https://atcoder.jp/contests/abc167/tasks/abc167_d

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 1
#if DEBUG
  #define _GLIBCXX_DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 2*1e5;
const ll K_MAX = 1e18;

int N;
ll K;
vector<int> A;

vector<int> path;
vector<int> dist;

int main() {
  cin >> N >> K;
  A = vector<int>(N);
  REP(i, N) {
    int a;
    cin >> a;
    A[i] = a - 1;
  }

  path = vector<int>(N, -1);
  dist = vector<int>(N, -1);

  int v = 0;
  int d = 0;
  while (dist[v] < 0) {
    path[d] = v;
    dist[v] = d;
    v = A[v];
    d++;
  }

  // DUMP(path);
  // DUMP(dist);

  int m = d - dist[v];
  int r = dist[v];
  if (K >= d) K = r + (K - r) % m;
  cout << (path[K] + 1) << endl;
}
