#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
#define vall(x) (x).begin(), (x).end()
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
void solve(long long N, const std::vector<long long> x, const std::vector<long long> y)
{

  vector<int> idx;
  rep(i, N) if (x[i] != 0 || y[i] != 0) idx.push_back(i);
  sort(vall(idx), [&](int l, int r) -> bool {
    return atan2(y[l], x[l]) < atan2(y[r], x[r]);
  });
  double ans = 0;
  rep(i, 2 * idx.size()) rep(j, i + 1)
  {

    lli X = 0, Y = 0;
    if (i - j + 1 <= idx.size())
    {
      for (int k = j; k <= i; k++)
      {
        X += x[idx[k % idx.size()]];
        Y += y[idx[k % idx.size()]];
      }
      chmax(ans, sqrt(X * X + Y * Y));
    }
  }
  printf("%.10f", ans);
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> x(N);
  std::vector<long long> y(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &x[i]);
    scanf("%lld", &y[i]);
  }
  solve(N, std::move(x), std::move(y));
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
