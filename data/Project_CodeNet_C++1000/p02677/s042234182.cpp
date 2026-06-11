#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const double PI = acos(-1);


int main(){
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double sh, lh, arg;
  sh = h * 5 + m / 12;
  lh = m;
  arg = abs(sh - lh) / 60;
  double ans;
  ans = sqrt(a*a + b*b - 2*a*b*cos(2*PI*arg));
  cout << fixed << setprecision(12) << ans << endl;
}