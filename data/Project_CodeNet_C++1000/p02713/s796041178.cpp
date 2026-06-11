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

ll ans = 0, K;

ll GCD(ll A, ll B){
  if (A < B) swap(A, B);
  while (A % B != 0){
    A %= B; swap(A, B);
  }
  return B;
}

int DFS(ll G, int turn){
  if (turn == 3){
    ans += G; return 0;
  }
  if (turn == 0){
    for (int i = 1; i <= K; i++){
      DFS(i, 1);
    }
    return 0;
  }

  for (int i = 1; i <= K; i++){
    DFS(GCD(G, i), turn + 1);
  }

  return 0;
}

int main(){
  cin >> K;
  DFS(0, 0);
  cout << ans << endl;

  return 0;
}
