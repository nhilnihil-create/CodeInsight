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

void solve(long long N, std::vector<long long> A)
{
  auto B = std::accumulate(vall(A), 0ll, [](auto l, auto r) { return l ^ r; });

  vector<lli> even;
  lli ret = 0;
  lli iter = 0;
  rrep(i, 60)
  {
    if (((B >> i) & 1))
    {
      ret += 1ll << i;
    }
    else
      iter |= 1ll << i;
  }
  lli rem = B - ret;
  vector<lli> mat = A;
  rep(i, N) mat[i] &= iter;
  lli rnk = 0;
  rep(i, 60)
  {
    lli idx = 59 - i;
    lli up = -1;
    for (int j = rnk; j < N; j++)
    {
      if ((mat[j] >> idx) & 1)
      {
        up = j;
        break;
      }
    }
    if (up < 0)
      continue;
    swap(mat[up], mat[rnk]);
    for (int j = 0; j < N; j++)
    {
      if (j != rnk && (mat[j] >> idx) & 1)
        mat[j] = mat[j] ^ mat[rnk];
    }
    rnk++;
  }
  // rep(i, N)
  // {
  //   cout << std::bitset<10>(mat[i]) << " ";
  // }
  lli ans = 0;
  lli tmp = iter;
  rep(i, rnk)
  {
    ans ^= mat[i];
  }
  cout << ret + ans * 2 << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
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
