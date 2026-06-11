#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;
  cin >> n;

  vector<ll> h(n + 1);
  rep(i, n) cin >> h.at(i);
  h.at(n) = 1e9;

  // cout << h.at(n);

  ll now = 0;

  rep(i, n)
  {
    now = max(h.at(i), now);
    if (now > h.at(i))
    {
      if (now-1 != h.at(i))
      {
        cout << "No";
        return 0;
      }
    }
  }

  cout << "Yes";
}
