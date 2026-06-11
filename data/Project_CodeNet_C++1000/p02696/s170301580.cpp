#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll A,B,N; cin >> A >> B >> N;
  ll ans = 0;
  ll tmp;
  tmp = min(B-1,N);
  ans = A * tmp / B - A * (tmp / B);
  cout << ans << endl;
}