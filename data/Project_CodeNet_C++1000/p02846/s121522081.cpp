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
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

int main()
{
  ll T, t, A, a, B, b;
  cin >> T >> t >> A >> a >> B >> b;

  ll d1 = T * A - T * B;
  ll d2 = (T * A + t * a) - (T * B + t * b);
  if (d1 > 0)
    d1 *= -1, d2 *= -1;
  cerr << d1 << " " << d2 << endl;

  if (d2 == 0)
    FINALANS("infinity");
  if (d2 < 0)
    FINALANS(0);

  ll n = -d1 / d2;
  cout << 2 * n + (-d1 % d2 != 0) << endl;
}