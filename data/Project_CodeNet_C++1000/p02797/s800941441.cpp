#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

ll N, K, S;
ll ans[int(1e5+5)];

int main(){
  cin >> N >> K >> S;
  for (int i = 0; i < K; i++) ans[i] = S;
  if (S == 1e9){
    for (int i = K; i < N; i++) ans[i] = 1e9 - 1;
  }else{
    for (int i = K; i < N; i++) ans[i] = 1e9;
  }

  cout << ans[0];
  for (int i = 1; i < N; i++) cout << " " << ans[i];
  cout << endl;

  return 0;
}
