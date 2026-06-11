#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  string S;
  cin >> S;
  // ll N = 5000;
  // string S = "";
  // for (ll i = 0; i < N; ++i)
  // {
  //   S += 'a';
  // }
  ll ans = 0;
  for (ll i = 0; i < N - 1; ++i)
  {
    for (ll j = i + 1 + ans; j < N - ans; ++j)
    {
      if (S[i] == S[j])
      {
        ll temp = 0;
        for (ll k = 0; k < j - i; ++k)
        {
          if (S[i + k] == S[j + k])
          {
            temp += 1;
            continue;
          }
          break;
        }
        ans = max(ans, temp);
      }
    }
  }
  cout << ans << endl;
}
