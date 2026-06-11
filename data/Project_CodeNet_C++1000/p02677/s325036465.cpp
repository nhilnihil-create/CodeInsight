#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b,h,m;
  cin >> a >> b >> h >> m;
  double angle;
  angle = 30*h - 5.5*m;
  
  
  
 double ans =  a*a + b*b - 2*a*b*cos(3.141592653589793 / 180 * angle);
 cout << fixed << setprecision(11);
 cout << sqrt(ans) << endl;
}