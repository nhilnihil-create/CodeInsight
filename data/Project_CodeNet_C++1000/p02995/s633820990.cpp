#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
 
 ll a,b,c,d;
ll f(ll x){
  return x-(x/c + x/d - x/lcm(c,d));
}
int main() {
 cin >> a >> b >> c >> d;
 cout << f(b) - f(a-1) << endl;
}