#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

#define REP(i,n) for(ll i=0; (i)<(n); ++(i))
#define P M_PI/3

typedef struct dot{
  double x; double y;
}T;

void kohho(T a, T b, ll n){
  if(n == 0){
    cout << b.x << " " << b.y << "\n";
    return;
  }
  T c, d, e;
  c.x = (2*a.x+b.x)/3, c.y = (2*a.y+b.y)/3;
  d.x = (2*b.x+a.x)/3, d.y = (2*b.y+a.y)/3;
  e.x = c.x + cos(P)*(d.x-c.x) - sin(P)*(d.y-c.y);
  e.y = c.y + sin(P)*(d.x-c.x) + cos(P)*(d.y-c.y);
  kohho(a, c, n-1);
  kohho(c, e, n-1);
  kohho(e, d, n-1);
  kohho(d, b, n-1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(8);
  
  T a = {0, 0}, b = {100, 0};
  ll n; cin >> n;
  cout << a.x << " " << a.y << "\n";
  kohho(a, b, n);
  return 0;
}
