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

int N, M;
ll A[1005], Key[1005], DP[1005][(1<<12)];

int main(){
  cin >> N >> M;
  for (int i = 1; i <= M; i++){
    int B;
    cin >> A[i] >> B;
    for (int j = 0; j < B; j++){
      int C; cin >> C;
      Key[i] += (1 << (C - 1));
    }
  }

  fill((ll*)DP, (ll*)(DP + M + 1), 1e18);
  DP[0][0] = 0;
  for (int i = 1; i <= M; i++){
    for (int j = 0; j < (1<<N); j++){
      DP[i][j] = DP[i-1][j];
    }
    for (int j = 0; j < (1<<N); j++){
      DP[i][(j|Key[i])] = min(DP[i][(j|Key[i])], DP[i-1][j] + A[i]);
    }
  }
  ll ans = DP[M][(1<<N)-1];
  if (ans == 1e18) ans = -1;
  cout << ans << endl;

  return 0;
}
