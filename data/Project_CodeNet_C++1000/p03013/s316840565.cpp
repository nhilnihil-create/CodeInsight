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
ll DP[int(1e5+5)];
bool flag[int(1e5+5)];

int main(){
  cin >> N >> M;
  for (int i = 0; i < M; i++){
    int A; cin >> A;
    flag[A] = true;
  }

  DP[0] = 1;
  for (int i = 0; i <= N; i++){
    if (flag[i]) continue;
    DP[i] %= MOD;
    DP[i+1] += DP[i];
    DP[i+2] += DP[i];
  }
  cout << DP[N] << endl;

  return 0;
}
