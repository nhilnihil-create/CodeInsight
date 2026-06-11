#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;


int main()
{
  ll M;
  cin >> M;
  ll d, c;
  ll S = 0;
  ll ans = -1;
  for (ll i = 0; i < M; ++i)
  {
    cin >> d >> c;
    S += d * c;
    ans += c;
  }
  while (S / 10 != 0)
  {
    ans += S / 10;
    S = S / 10 + S % 10;
  }
  cout << ans << endl;
}
