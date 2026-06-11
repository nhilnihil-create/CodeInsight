#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
 
ll f(ll x, ll c, ll d){
  return x-(x/c + x/d - x/lcm(c,d));
}
int main() {
 ll a,b,c,d;
 cin >> a >> b >> c >> d;
 cout << f(b,c,d) - f(a-1,c,d) << endl;
}