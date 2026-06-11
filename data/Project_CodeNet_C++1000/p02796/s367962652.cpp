#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1LL << 60);

int main()
{
  int N;
  cin >> N;
  vector<pair<ll, ll>> r(N);
  for (int i = 0; i < N; i++)
  {
    ll X, L;
    cin >> X >> L;
    r.at(i) = make_pair(X + L, X - L);
  }
  sort(r.begin(), r.end());
  int ans = 0;
  ll last = -INF;
  for (int i = 0; i < N; i++)
  {
    if (last <= r.at(i).second)
    {
      ans++;
      last = r.at(i).first;
    }
  }
  cout << ans << endl;
}