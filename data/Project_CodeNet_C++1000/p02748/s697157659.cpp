#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  vector<int> x(M), y(M), c(M);
  rep(i, A)
  {
    cin >> a[i];
  }
  rep(i, B)
  {
    cin >> b[i];
  }
  int minA = *min_element(a.begin(), a.end());
  int minB = *min_element(b.begin(), b.end()); // 最小値のイテレータを返してくれる
  int ans = minA + minB;
  for (int i = 0; i < M; i++)
  {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    ans = min(ans, a[x] + b[y] - c);
  }
  cout << ans << endl;
  return 0;
}