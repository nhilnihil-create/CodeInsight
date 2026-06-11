#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
void solve(void)
{
  int n;
  cin >> n;
  vector<int> L(n);
  rep(i, n) cin >> L[i];
  sort(L.begin(), L.end());
  int ans = 0;
  rep(i, n - 2)
  {
    for (int j = i + 1; j < n - 1; ++j)
    {
      //二分探索する
      int a = L[i];
      int b = L[j];
      int c = a + b;
      int l = j;
      int r = n;
      int mid = (l + r) / 2;

      while (r - l > 1)
      {
        mid = (l + r) / 2;
        if (L[mid] >= c)
          r = mid;
        else
          l = mid;
      }

      // cout << i << ":" << j << "  " << c << " " << L[mid] << endl;
      ans += l - j;
    }
  }
  cout << ans << endl;
}
int main(void) { solve(); }
