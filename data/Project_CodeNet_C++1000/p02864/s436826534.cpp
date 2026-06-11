#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
template <class T1, class T2>
void vadd(vector<T1> &v, T2 x);

#define int long long int
lli dp[305][305][305] = {};
// dp[i][j][k] := iまで見てj回変更して最後の高さはh[k]に等しい
void solve(long long N, long long K, std::vector<long long> H)
{
  H.push_back(0);
  N++;
  rep(i, N + 1) rep(j, N + 1) rep(k, N + 1) dp[i][j][k] = 1e18;
  dp[1][0][0] = H[0];

  for (int i = 1; i < N; i++)
    dp[1][1][i] = H[i];
  for (int i = 1; i < N; i++)
  {
    rep(j, K + 1) rep(k, N)
    {
      chmin(dp[i + 1][j + 1][k], dp[i][j][k]);
      chmin(dp[i + 1][j][i], dp[i][j][k] + max(H[i] - H[k], 0ll));
    }
  }
  lli ans = 1e18;
  rep(i, K + 1) rep(j, N)
      chmin(ans, dp[N][i][j]);

  cout << ans << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> H(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &H[i]);
  }
  solve(N, K, std::move(H));
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}

template <class T1, class T2>
void vadd(vector<T1> &v, T2 x)
{
  for (auto &s : v)
    s += T2(x);
}
