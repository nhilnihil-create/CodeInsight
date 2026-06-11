#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll Pow(ll A, ll N){
  if (N == 0) return 1;
  if (N % 2 == 0) return Pow(A * A % MOD, N / 2);
  return Pow(A * A % MOD, N / 2) * A % MOD;
}

int Solve(ll A, ll B){
  ll ans = 1;
  for (ll i = 1; i <= A + B; i++){
    ans *= i; ans %= MOD;
  }
  ll now = 1;
  for (ll i = 1; i <= A; i++){
    now *= i; now %= MOD;
  }
  ans *= Pow(now, MOD - 2); ans %= MOD;
  now = 1;
  for (ll i = 1; i <= B; i++){
    now *= i; now %= MOD;
  }
  ans *= Pow(now, MOD - 2); ans %= MOD;
  cout << ans << endl;

  return 0;
}

int main(){
  ll X, Y; cin >> X >> Y;

  if ((-1 * X + 2 * Y) % 3 != 0 || (2 * X - Y) % 3 != 0){
    cout << 0 << endl;
    return 0;
  }

  ll A = (-1 * X + 2 * Y) / 3;
  ll B = (2 * X - Y) / 3;

  if (A < 0 || B < 0){
    cout << 0 << endl;
    return 0;
  }

  Solve(A, B);

  return 0;
}
