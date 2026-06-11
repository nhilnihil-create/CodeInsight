// https://atcoder.jp/contests/abc140/tasks/abc140_f

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(i, n) printf("%d%c", a[i], i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(i, n) REP(j, m) printf("%d%c", a[i][j], j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 18;
const int S_I_MAX = 1e9;
const int K_MAX = 1 << N_MAX;

int N, K;
int S[K_MAX];
multiset<int> T;
vector<int> V;

void pick(multiset<int>::iterator it) {
  V.push_back(*it);
  T.erase(it);
}

void solve() {
  REP(i, K) T.insert(S[i]);
  pick(--T.end());
  // DUMP(V, V.size());
  REP(i, N) {
    int m = V.size();
    REP(j, m) {
      auto it = T.lower_bound(V[j]);
      // printf("i = %d, j = %d, *it = %d\n", i, j, *it);
      if (it == T.begin()) {
        puts("No");
        return;
      }
      pick(--it);
    }
    // DUMP(V, V.size());
    sort(V.begin(), V.end(), greater<int>());
  }
  puts("Yes");
}

void input() {
  scanf("%d", &N);
  K = 1 << N;
  REP(i, K) scanf("%d", S + i);
}

int main() {
  input();
  solve();
  return 0;
}
