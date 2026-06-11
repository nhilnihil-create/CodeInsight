#include <bits/stdc++.h>
#define INF 1000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

//=============z_algorithm============================
ll z_algorithm(string S)
{
  vector<ll> Z(S.size(), 0);
  ll res = 0;
  ll i = 1, j = 0;
  while (i < S.size())
  {
    while (i+j < S.size() && S[j] == S[i+j]) ++j;
    Z.at(i) = j;
    if (i >= j)
    {
      res = max(res, j);
    }
    if (j == 0) { ++i; continue;}
    ll k = 1;
    while (i+k < S.size() && k+Z.at(k) < j) Z.at(i + k) = Z.at(k), ++k;
    i += k; j -= k;
  }
  return res;
}
//=================================================

int main()
{
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll ans = 0;
  for (ll i = 0; i < N; ++i)
  {
    ll temp = z_algorithm(S.substr(i, S.size() - i));
    ans = max(ans, temp);
    // cout << ans << endl;
  }
  cout << ans << endl;
}
