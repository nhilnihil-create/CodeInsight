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

int N, K;
double P[int(2e5+5)], sum[int(2e5+5)];

int main(){
  cin >> N >> K;
  for (int i = 1; i <= N; i++){
    cin >> P[i]; P[i]++;
    sum[i] = sum[i-1] + P[i];
  }

  double M = sum[K];
  for (int i = K; i <= N; i++){
    M = max(sum[i] - sum[i - K], M);
  }
  cout << setprecision(16) << M / 2 << endl;

  return 0;
}
