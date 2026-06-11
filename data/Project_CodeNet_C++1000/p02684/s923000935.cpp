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

int N; ll K;
int A[int(2e5+5)], Table[100][int(2e5+5)];

int main(){
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    Table[0][i] = A[i];
  }

  for (int i = 1; i < 100; i++){
    for (int j = 1; j <= N; j++){
      Table[i][j] = Table[i-1][Table[i-1][j]];
    }
  }

  int ans = 1;
  while (K > 0){
    for (ll i = 1; i < 100; i++){
      ll now = (ll)1 << i;
      if (K < now){
        ans = Table[i-1][ans];
        K -= now / 2;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
