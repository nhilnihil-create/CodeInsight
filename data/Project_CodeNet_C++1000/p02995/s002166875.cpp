#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll range = b - a + 1;
  ll div_c, div_d, div_cd;
  {
    ll bb = b / c;
    ll aa = a / c;
    if (a % c == 0) aa--;
    div_c = bb - aa;
  }
  {
    ll bb = b / d;
    ll aa = a / d;
    if (a % d == 0) aa--;
    div_d = bb - aa;
  }
  {
    ll lcm = c / __gcd(c,d) * d;
    ll bb = b / lcm;
    ll aa = a / lcm;
    if (a % lcm == 0) aa--;
    div_cd = bb - aa;
  }
  
  range = range - div_c - div_d + div_cd;
  cout << range << endl;
  return 0;
}