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
lli dp[3005][3005] = {};

void solve(long long N, long long T, std::vector<long long> A,
           std::vector<long long> B)
{
  lli ret = 0;
  vector<pair<int, int>> v;
  rep(i, N) v.emplace_back(A[i], B[i]);
  sort(v.begin(), v.end());
  rep(i, N) A[i] = v[i].first, B[i] = v[i].second;

  rep(i, N) rep(j, T)
  {
    chmax(dp[i + 1][j], dp[i][j]);
    if (j + A[i] < T)
    {
      chmax(dp[i + 1][j + A[i]], dp[i][j] + B[i]);
    }
    else
    {
      chmax(ret, dp[i][j] + B[i]);
    }
    chmax(ret, dp[i][j]);
  }
  cout << ret << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  long long T;
  scanf("%lld", &T);
  std::vector<long long> A(N);
  std::vector<long long> B(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
    scanf("%lld", &B[i]);
  }
  solve(N, T, std::move(A), std::move(B));
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
