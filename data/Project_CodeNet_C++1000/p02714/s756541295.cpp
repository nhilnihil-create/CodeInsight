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

ll N, cnt[3];
char C[3] = {'R', 'G', 'B'}; 
string S;

int main(){
  cin >> N >> S;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < 3; j++){
      if (S[i] == C[j]) cnt[j]++;
    }
  }

  ll ans = cnt[0] * cnt[1] * cnt[2];

  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      int k = 2 * j - i;
      if (k >= N) break;
      if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) ans--;
    }
  }
  cout << ans << endl;

  return 0;
}
