#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int N, M, Q, ans;
int a[50], b[50], c[50], d[50];
int A[10];

void dfs(int depth, int now) {
  if (depth == N) {
    int tmp = 0;
    rep(i, Q) {
      if (A[b[i] - 1] - A[a[i] - 1] == c[i]) tmp += d[i];
    }
    ans = max(tmp, ans);
    return;
  }

  for (int i = now; i <= M; i++) {
    A[depth] = i;
    dfs(depth + 1, i);
  }
}

int main() {
  cin >> N >> M >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  A[0] = 1;
  dfs(1, 1);
  cout << ans << endl;
}