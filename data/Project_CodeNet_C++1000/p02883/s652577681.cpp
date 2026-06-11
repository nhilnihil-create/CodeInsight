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

void solve(long long N, long long K, std::vector<long long> A,
           std::vector<long long> F)
{
  lli up = 1e18, low = -1;
  sort(A.rbegin(), A.rend());
  sort(F.begin(), F.end());
  while (up - low > 1)
  {
    lli mid = (up + low) / 2;
    lli ret = 0;
    rep(i, N)
    {
      // F[i] * (A[i]-k_i) <= mid
      // にするのに必要なk_i
      // A[i] - (mid+F[i]-1)/F[i] <= k_i
      ret += max(0ll, A[i] - mid / F[i]);
    }
    (ret <= K ? up : low) = mid;
  }
  cout << up << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }
  std::vector<long long> F(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &F[i]);
  }
  solve(N, K, std::move(A), std::move(F));
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
