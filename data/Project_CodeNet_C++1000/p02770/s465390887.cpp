#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

int main()
{
  ll K, Q;
  cin >> K >> Q;
  vector<ll> D(K);
  for (ll i = 0; i < K; i++)
  {
    cin >> D.at(i);
  }

  for (ll q = 0; q < Q; q++)
  {
    ll N, X, M;
    cin >> N >> X >> M;

    vector<ll> d(K);
    for (ll i = 0; i < K; i++)
    {
      d.at(i) = D.at(i) % M;
    }

    vector<ll> T(K);
    for (ll i = 0; i < K; i++)
    {
      T.at(i) = (N - 1) / K + (i < (N - 1) % K);
    }

    ll tmp0 = 0;
    for (ll i = 0; i < K; i++)
    {
      tmp0 += T.at(i) * (d.at(i) == 0);
    }

    ll last = X;
    for (ll i = 0; i < K; i++)
    {
      last += T.at(i) * d.at(i);
    }
    ll tmp1 = last / M - X / M;

    ll ans = (N - 1) - (tmp0 + tmp1);
    cout << ans << endl;
  }
}