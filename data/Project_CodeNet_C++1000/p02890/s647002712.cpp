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
int cnt[300005] = {};
int cnt2[300005] = {};
int cnt3[300005] = {};
void solve(long long N, std::vector<long long> A)
{
  rep(i, N) cnt[A[i]]++;
  vector<int> a;
  vector<int> hist;
  rep(i, 300005)
  {
    if (cnt[i])
    {
      cnt2[cnt[i]]++;
    }
  }
  map<lli, lli> m;
  lli sum = 0;
  lli used = 0;
  rep(i, 300005) used += cnt2[i];
  //cout << used << endl;
  rep(i, 300005)
  {
    sum += cnt2[i] * i;
    used -= cnt2[i];
    if (i)
      cnt3[i] = (sum + i * used) / i;
    // sum_i min(i,) * cnt[i]
    //cout << cnt3[i] << endl;
  }
  lli cur = N;
  for (int k = 1; k <= N; k++)
  {
    while (cur >= 0 && cnt3[cur] < k)
      cur--;

    cout << (cur > 0 ? cur : 0) << endl;
  }
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
