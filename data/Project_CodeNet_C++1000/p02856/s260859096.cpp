#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main()
{
  int M;
  cin >> M;
  ll n = 0, s = 0;
  rep(i, M)
  {
    ll d, c;
    cin >> d >> c;
    n += c;
    s += d * c;
  }
  cout << n - 1 + (s - 1) / 9 << endl;
}