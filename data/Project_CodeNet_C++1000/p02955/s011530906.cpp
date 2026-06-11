// https://atcoder.jp/contests/abc136/tasks/abc136_e

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

//------------------------------------------------------------------------------
vector<int> divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

//------------------------------------------------------------------------------
const int N_MAX = 500;
const int A_I_MAX = 1e6;
const int K_MAX = 1e9;

int N, K;
int A[N_MAX];
int sum;
vector<int> ds;

bool check(int d) {
  vector<int> qs;
  int qsum = 0;
  REP(i, N) {
    int q = A[i] % d;
    if (q > 0) {
      qs.push_back(q);
      qsum += q;
    }
  }
  sort(qs.begin(), qs.end());
  int k = 0;
  for (int i = 0; i < qs.size() - qsum / d; i++) k += qs[i];
  return k <= K;
}

void solve() {
  sum = 0;
  REP(i, N) sum += A[i];
  ds = divisor(sum);
  sort(ds.begin(), ds.end(), greater<int>());
  for (int d: ds) {
    if (check(d)) {
      printf("%d\n", d);
      break;
    }
  }
}

void input() {
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", A + i);
}

int main() {
  input();
  solve();
  return 0;
}
