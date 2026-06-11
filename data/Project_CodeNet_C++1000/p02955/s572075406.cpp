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
#define int long long int
constexpr int A_max = 1000005;
void solve(long long N, long long K, std::vector<long long> A)
{
  set<int> Fac;
  Fac.insert(1);
  lli all = accumulate(A.begin(), A.end(), 0ll);
  for (lli i = 2; i * i <= all; i++)
  {
    if (all % i == 0)
    {
      Fac.insert(i);
      Fac.insert(all / i);
    }
  }
  Fac.insert(all);
  lli ans = 0;
  for (auto s : Fac)
  {
    lli ret = 0;
    vector<lli> B;
    rep(i, N) if (A[i] % s) B.push_back(A[i] % s);
    sort(B.begin(), B.end());
    lli minus = accumulate(B.begin(), B.end(), 0ll);
    lli plus = 0;
    //   cerr << s << " " << minus << endl;

    rrep(i, B.size())
    {
      if (minus == plus && minus <= K)
      {
        chmax(ans, s);
      }
      minus -= B[i];
      plus += s - B[i];
      //      cerr << minus << " " << plus << " " << B[i] << " " << K << endl;
    }
    if (minus == plus && minus <= K)
    {
      chmax(ans, s);
    }
  }
  cout << ans << endl;
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
  solve(N, K, std::move(A));
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
