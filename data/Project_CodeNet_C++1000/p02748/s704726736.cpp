#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  int mina = INT32_MAX, minb = INT32_MAX;
  rep(i, A)
  {
    cin >> a[i];
    mina = min(a[i], mina);
  }
  rep(i, B)
  {
    cin >> b[i];
    minb = min(b[i], minb);
  }
  long long ans = mina + minb;
  rep(i, M)
  {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    long long price = a[x] + b[y] - c;
    ans = min(ans, price);
  }
  cout << ans << endl;
  return 0;
}