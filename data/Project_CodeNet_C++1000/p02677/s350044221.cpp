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
  double A,B;
  cin >> A >> B;
  double H,M;
  cin >> H >> M;
  double pi = 3.1415926535;
  double rad1 = H / 6 * pi + M * pi / 360;
  double rad2 = M * pi / 30;
  double ans = A*A + B*B - 2 * A * B * cos(rad2-rad1);
  cout << pow(ans,0.5) << endl;
  return 0;
}
