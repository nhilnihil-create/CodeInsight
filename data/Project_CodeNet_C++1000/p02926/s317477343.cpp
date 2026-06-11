#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

ll quadrant(pair<ll, ll> xy)
{
  ll x = xy.first, y = xy.second;
  if (x >= 0 && y >= 0)
    return 1;
  if (x < 0 && y >= 0)
    return 2;
  if (x < 0 && y < 0)
    return 3;
  if (x >= 0 && y < 0)
    return 4;

  return 0;
}

bool comp(pair<ll, ll> xy1, pair<ll, ll> xy2)
{
  ll q1 = quadrant(xy1), q2 = quadrant(xy2);
  if (q1 != q2)
    return (q1 < q2);
  
  ll x1 = xy1.first, y1 = xy1.second;
  ll x2 = xy2.first, y2 = xy2.second;
  return (x2 * y1 < x1 * y2);
}

int main()
{
  ll N;
  cin >> N;
  vector<pair<ll, ll>> XY;
  for (ll i = 0; i < N; i++)
  {
    ll x, y;
    cin >> x >> y;
    if (!(x == 0 && y == 0))
      XY.push_back(make_pair(x, y));
  }
  N = XY.size();

  sort(XY.begin(), XY.end(), comp);

  for (ll i = 0; i < N; i++)
  {
    XY.push_back(XY.at(i));
  }

  ll ans = 0;
  for (ll i = 0; i < N; i++)
  {
    ll X = 0, Y = 0;

    for (ll j = i; j < i + N; j++)
    {
      ll x = XY.at(j).first, y = XY.at(j).second;
      X += x, Y += y;
      
      ll tmp = X * X + Y * Y;
      chmax(ans, tmp);
    }
  }
  cout << fixed << setprecision(20) << sqrt(ans) << endl;
}