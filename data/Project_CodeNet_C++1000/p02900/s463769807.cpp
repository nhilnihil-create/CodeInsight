#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

int main() {
  ll A, B;
  cin >> A >> B;

  
  vector<ll> C;
  ll num = GCD(A, B);
  ll ans = 1;
  
  for(ll i = 2; i * i <= num; i++) {
    if(num % i != 0) continue;
    ll ex = 0;
    while(num % i == 0) {
      if(ex == 0) ans++;
      ++ex;
      num /= i;
    }
  }

  if(num != 1) ans++;

 cout << ans;
   return 0;
}