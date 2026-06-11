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

int N, P[55];

bool Judge(){
  for (int i = 0; i < N - 1; i++){
    if (P[i] > P[i+1]) return false;
  }
  return true;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i];
  if (Judge()){
    YES(); return 0;
  }

  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      swap(P[i], P[j]);
      if (Judge()){
        YES(); return 0;
      }
      swap(P[i], P[j]);
    }
  }
  NO();

  return 0;
}
