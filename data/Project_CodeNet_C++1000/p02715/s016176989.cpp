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
  else return Pow(A * A % MOD, N / 2) * A % MOD;
}

ll N, K;
ll DP[int(1e5+5)];

int main(){
  cin >> N >> K;
  for (ll i = K; i >= 1; i--){
    DP[i] = Pow(K / i, N);

    ll sum = 0;
    for (ll j = 2 * i; j <= K; j += i){
      sum += DP[j]; sum %= MOD;
    }
    DP[i] -= sum; DP[i] %= MOD;
    if (DP[i] < 0) DP[i] += MOD;
  }

  ll ans = 0;
  for (ll i = 1; i <= K; i++){
    ans += i * DP[i]; ans %= MOD; 
  }
  cout << ans << endl;

  return 0;
}
