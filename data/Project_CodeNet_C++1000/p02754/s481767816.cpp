#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  ll n,a,b; 
  cin >> n >> a >> b;
  ll ans = 0;
  ll c = n / (a+b);
  n -= c*(a+b);
  
  ans += c * a;
  if(n >= a) ans += a;
  else ans += n;

  cout << ans << endl;
  
}