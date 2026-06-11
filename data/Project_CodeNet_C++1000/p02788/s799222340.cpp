#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 2e5+1;
int n, D, A, R[N];
long psum[N + 1];
pii a[N];

int main()
{
  fastio;
  cin >> n >> D >> A;
  for (int i = 1; i <= n; i++){
    cin >> a[i].first >> a[i].second;
    a[i].second = (a[i].second + A - 1) / A;
  }
  sort(a + 1, a + 1 + n);
  int ptr = 1;
  for (int i = 1; i <= n; i++){
    while (ptr <= n && a[ptr].first - a[i].first <= 2 * D) ptr++;
    R[i] = ptr;
  }
  long res = 0;
  for (int i = 1; i <= n; i++){
    psum[i] += psum[i - 1];
    long cur = max(0ll, psum[i] + a[i].second);
    res += cur; psum[i] -= cur; psum[R[i]] += cur;
  }
  cout << res;
  return 0;
}