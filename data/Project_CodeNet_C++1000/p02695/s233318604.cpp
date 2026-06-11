#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

int N, M, Q;
int ans = 0;
vector<int> a, b, c, d;

void dfs(vector<int> &A)
{
  rep(i, A.size() - 1)
  {
    if (A[i] > A[i + 1])
      return;
  }
  // 数列の長さが N に達したら打ち切り
  if (A.size() == N)
  {
    int score = 0;
    rep(i, Q)
    {
      if (A[b[i]] - A[a[i]] == c[i])
        score += d[i];
    }
    ans = max(score, ans);
    return;
  }
  for (int v = 1; v <= M; ++v)
  {
    A.push_back(v);
    dfs(A);
    A.pop_back();
  }
}
int main()
{
  cin >> N >> M >> Q;
  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);
  rep(i, Q)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
  }
  vector<int> A(0);
  dfs(A);
  cout << ans << endl;
  return 0;
}