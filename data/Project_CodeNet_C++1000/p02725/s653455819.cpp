#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int a[200000], dist[200000];

int main()
{
  int k, n, result = 0;
  cin >> k >> n;

  REP(i, n)
  {
    cin >> a[i];
  }
  dist[0] = k - a[n - 1] + a[0];
  FOR(i, 1, n)
  {
    dist[i] = a[i] - a[i - 1];
  }
  sort(dist, dist + n);
  result = k-dist[n-1];

  cout << result << endl;
}