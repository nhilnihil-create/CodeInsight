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

ll K, N, A[int(2e5+5)];

int main(){
  cin >> K >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  ll ans = A[0] + K - A[N-1];
  for (int i = 0; i < N; i++){
    ans = max(ans, A[i+1] - A[i]);
  }
  cout << K - ans << endl;

  return 0;
}

