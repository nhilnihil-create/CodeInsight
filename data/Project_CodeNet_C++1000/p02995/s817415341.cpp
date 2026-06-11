#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main()
{
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  ll a = B / C - (A-1) / C;
  ll b = B / D - (A-1) / D;
  ll c = lcm(C, D);
  ll m = max((ll)0, (B/c - (A-1)/c));
  cout << B - (A-1) - (a + b - m) << endl;
  
  return 0;
}