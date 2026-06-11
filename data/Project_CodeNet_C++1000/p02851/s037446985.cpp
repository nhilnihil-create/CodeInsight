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
lli su[200005] = {};
lli bi[200005] = {};
void solve(long long N, long long K, std::vector<long long> A)
{
  rep(i, N) A[i] %= K;
  map<lli, lli> s;
  rep(i, N) su[i + 1] = A[i] + su[i];
  rep(i, N + 1) bi[i] = ((su[i] - i) % K + K) % K;
  map<lli, lli> key;
  lli ans = 0;
  rep(i, N + 1)
  {
    ans += key[bi[i]];
    key[bi[i]]++;
    if (i >= K - 1)
      key[bi[i - K + 1]]--;
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
