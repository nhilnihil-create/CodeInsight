#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

const int N = 3e2+1;

ll d[N][N], h[N];
int n, k;

inline ll get(int i, int j)
{
  return max(0ll, h[j]-h[i]);
}
inline void Min(ll &x, ll y)
{
  if (x > y) x = y;
}
ll dp(int sz, int end_at)
{
  ll &ret = d[sz][end_at];
  if (ret == -1)
    {
      if (sz == 0) return ret = 0;
      else if (end_at == 0) return ret = LLONG_MAX>>1;
      else if (sz == 1) return ret = get(0, end_at);
      ret = LLONG_MAX;
      for (int j = 0; j < end_at; ++j)
	Min(ret, dp(sz-1, j) + get(j, end_at));
      //      printf("dp[%d][%d] = %lld\n", sz, end_at, ret);
    }
  return ret;
}
int main()
{
  while (~scanf("%d %d", &n, &k))
    {
      for (int i = 1; i <= n; ++i) scanf("%lld", h+i);
      memset(d, -1, sizeof(d));
      ll ret = LLONG_MAX;
      for (int i = n-k; i <= n; ++i) Min(ret, dp(n-k, i));
      printf("%lld\n", ret);
    }
}
