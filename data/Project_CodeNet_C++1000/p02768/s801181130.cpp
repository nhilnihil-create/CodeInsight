#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll modnum = 1000000007;

//繰り返し二乗法
ll RepeatSquaring(ll a, ll n, ll p) {
  if (n == 0) return 1;
  if (n == 1) return a % modnum;
  if (n % 2 == 1) return (a * RepeatSquaring(a, n - 1, modnum)) % p;
  ll t = RepeatSquaring(a, n / 2, modnum);
  return (t * t) % modnum;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  
  ll tmp;
  ll ans = 1;

  ans = RepeatSquaring(2, n, modnum);
  
  ll cmb_a=1, cmb_b=1;
  ll bunbo_a=1, bunbo_b=1;

  for(ll i = 1; i <= a; i++) {
    cmb_a = ((cmb_a * (n-i+1) % modnum) * RepeatSquaring(i, modnum-2, modnum)) % modnum;
  }
  for(ll i = 1; i <= b; i++) {
    cmb_b = ((cmb_b * (n-i+1) % modnum) * RepeatSquaring(i, modnum-2, modnum)) % modnum;
  }

  ll  sub =  (cmb_a + cmb_b + 1) % modnum;
  ans = (ans - sub) % modnum;
  while(ans < 0) {
    ans = ans + modnum;
  }

  cout << ans << endl;

  return 0;
}