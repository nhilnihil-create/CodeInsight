#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define int long long
using namespace std;

const int P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

signed main()
{
  cout << fixed << setprecision(10);
  int M1, D1, M2, D2;
  cin >> M1 >> D1 >> M2 >> D2;
  bool answer = false;
  if (M2-M1==1)
  {
    cout << 1 << endl;
    answer = true;
  }
  if (answer==false)
  {
    cout << 0 << endl;
  }
  return 0;
}
