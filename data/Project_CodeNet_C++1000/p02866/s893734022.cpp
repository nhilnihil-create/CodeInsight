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

ll cnt[int(1e5 + 5)];

ll Pow(ll A, ll N){
  if (N == 0) return 1;
  if (N % 2 == 0) return Pow(A*A%MOD2, N/2);
  else return A*Pow(A*A%MOD2, N/2) % MOD2;
}

int main(){
  int N; cin >> N;
  int M = 0;
  for (int i = 0; i < N; i++){
    int D; cin >> D;

    if (i == 0 && D != 0){
      cout << 0 << endl;
      return 0;
    }
    cnt[D]++;
    M = max(M, D);
  }

  if (cnt[0] != 1){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  for (int i = 1; i <= M; i++){
    ans *= Pow(cnt[i-1], cnt[i]);
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
