#include <bits/stdc++.h>

#define loop(s, e, i) for (int i=s; i<e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  while(b != 0) {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
  ll L, R;
  cin >> L >> R;
  ll m = 99999999;

  ll limit = min(L+2019, R);
  for(ll i=L; i<=limit; i++) {
    for (ll j=i+1; j<=limit; j++){
      m = min(i*j%2019, m);
    }
  }
  print(m);
}