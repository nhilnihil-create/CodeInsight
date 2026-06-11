#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int main()
{
  ll n, ans = INF, sum = 0;
  cin >> n;

  vector<int> x(n);
  REP(i,n){
    cin >> x[i];
  }
  FOR(i, 1, 100)
  {
    REP(j, n)
    {
      sum += (x[j] - i) * (x[j] - i);
    }
    if (sum < ans)
    {
      ans = sum;
    }
    sum = 0;
  }
  cout << ans << endl;
}