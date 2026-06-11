#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  reverse(S.begin(), S.end());
  vector<ll> ans;
  ll now = 0;
  while (now != N) {
    for (ll i = min(N - now, M); i >= 0; --i) {
      if (S[now + i] == '0') {
        if (i == 0) {
          cout << -1 << "\n";
          return 0;
        }
        ans.push_back(i);
        now += i;
        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  for (ll i = 0; i < ans.size(); ++i) {
    cout << ans.at(i) << " ";
  }
  cout << "\n";
}
