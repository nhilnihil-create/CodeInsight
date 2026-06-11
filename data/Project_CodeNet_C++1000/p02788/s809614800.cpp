#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
#define int long long int
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
lli imos[200005] = {};
void solve(long long N, long long D, long long A, std::vector<long long> X,
           std::vector<long long> H)
{
  vector<pair<lli, lli>> p;
  rep(i, N) p.emplace_back(X[i], H[i]);
  sort(p.begin(), p.end());
  lli cur = 0;
  lli ans = 0;
  rep(i, N)
  {
    lli y = p[i].first;

    cur += imos[i];
    //cout << y << " " << imos[i] << " " << cur << endl;
    lli rem = p[i].second - A * cur;

    if (rem > 0)
    {
      rem = (rem + A - 1) / A;
      cur += rem;
      ans += rem;
      int idx = std::upper_bound(p.begin(), p.end(), pair<lli, lli>(y + 2 * D, 1e9)) - p.begin();
      //cout << idx << endl;
      imos[idx] -= rem;
    }
  }
  cout << ans << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  long long D;
  scanf("%lld", &D);
  long long A;
  scanf("%lld", &A);
  std::vector<long long> X(N);
  std::vector<long long> H(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &X[i]);
    scanf("%lld", &H[i]);
  }
  solve(N, D, A, std::move(X), std::move(H));
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
