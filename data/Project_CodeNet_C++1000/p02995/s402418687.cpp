#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll a,b;
  cin >> a >> b;
  ll c,d;
  cin >> c >> d;  
  
  ll sum = 0,dif = 0;
  
  ll gc = gcd(c,d);
  ll e = d / gc;
  e *= c;
  
  sum += b;
  sum -= b/c;
  sum -= b/d;
  sum += b/e;
  
  dif += a;
  dif -= a/c;
  dif -= a/d;
  dif += a/e;
  
  ll ans = sum - dif;
  if(a % c != 0 && a % d != 0) ans++;
  cout << ans << endl;           
              
}