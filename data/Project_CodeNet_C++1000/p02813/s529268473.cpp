#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n), p(n), q(n);
  rep(i, n) a[i] = i + 1;
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  sort(a.begin(), a.end());
  int A = 0, B = 0, cnt = 0;
  do
  {
    cnt++;
    int cntA = 0, cntB = 0;
    rep(i, n)
    {
      if (a[i] == p[i])
        cntA++;
      if (a[i] == q[i])
        cntB++;
    }
    if (cntA == n)
      A = cnt;
    if (cntB == n)
      B = cnt;
  } while (next_permutation(a.begin(), a.end()));
  cout << abs(A - B) << endl;
  return 0;
}