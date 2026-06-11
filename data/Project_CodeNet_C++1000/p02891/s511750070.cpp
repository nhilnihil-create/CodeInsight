#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll calc(string S, ll rep)
{
  string temp_s = S;
  for (ll i = 0; i < rep - 1; ++i) {
    S = S + temp_s;
  }
  ll res = 0;
  ll cnt = 1;
  for (ll i = 1; i < S.size(); ++i) {
    if (S[i] == S[i - 1]) {
      cnt += 1;
    }
    else {
      if (cnt > 1) {
        res += cnt / 2;
      }
      cnt = 1;
    }
  }
  if (cnt > 1) {
    res += cnt / 2;
  }
  return res;
}

int main()
{
  string S;
  cin >> S;
  ll K;
  cin >> K;
  char temp = S[0];
  bool all_same = true;
  for (ll i = 0; i < S.size(); ++i) {
    if (S[i] == temp) {
      continue;
    }
    all_same = false;
    break;
  }
  if (all_same) {
    cout << S.size() * K / 2 << endl;
    return 0;
  }
  ll one = calc(S, 1);
  ll two = calc(S, 2);
  ll three = calc(S, 3);
  ll dif = three - two;
  ll ans = one + (K - 1) * dif;
  cout << ans << endl;
}
