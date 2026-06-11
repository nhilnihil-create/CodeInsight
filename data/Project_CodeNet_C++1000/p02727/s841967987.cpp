#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int main()
{
  ll X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;

  vector<ll> Ps, Qs, Rs;
  REP(i, A)
  {
    ll p;
    cin >> p;
    Ps.push_back(p);
  }
  REP(i, B)
  {
    ll q;
    cin >> q;
    Qs.push_back(q);
  }
  REP(i, C)
  {
    ll r;
    cin >> r;
    Rs.push_back(r);
  }
  sort(ALL(Ps), greater<ll>());
  sort(ALL(Qs), greater<ll>());
  sort(ALL(Rs), greater<ll>());
  Ps.erase(Ps.begin() + X, Ps.end());
  Qs.erase(Qs.begin() + Y, Qs.end());

  vector<ll> As;
  As.insert(As.end(), ALL(Ps));
  As.insert(As.end(), ALL(Qs));
  As.insert(As.end(), ALL(Rs));
  sort(ALL(As), greater<ll>());

  ll ans = 0;
  ll cnt = X + Y;
  for (auto a : As)
  {
    if (cnt == 0) break;

    ans += a;
    cnt--;
  }

  cout << ans << endl;

  return 0;
}