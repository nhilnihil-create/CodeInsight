#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  ll X,Y,A,B,C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A),q(B),r(C);
  rep(i,A) cin >> p[i];
  rep(i,B) cin >> q[i];
  rep(i,C) cin >> r[i];
  vector<ll> ans;
  sort(RALL(p));
  sort(RALL(q));
  ll sum = 0;
  ll sumr = 0;
  ll sumg = 0;
  rep(i,X)
  {
    ans.pb(p[i]);
  }
  rep(i,Y)
  {
    ans.pb(q[i]);
  }
  sort(ALL(ans));
  sort(RALL(r));
  ll D = min(C,X+Y);
  rep(i,D)
  {
    if(ans[i]<r[i])
    {
      swap(ans[i],r[i]);
    }
  }
  rep(i,X+Y)
  {
    sum += ans[i];
  }
  cout << sum << endl;
  return 0;
}
