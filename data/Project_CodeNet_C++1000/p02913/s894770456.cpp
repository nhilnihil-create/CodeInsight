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

int N, ans = 0;
string S, T;

int A[5005];
int Solve(){
  int t = T.length();
  fill(A, A + t, 0);
  A[0] = t;
  int i = 1, j = 0;
  while (i < t){
    while (i + j < t && T[j] == T[i+j]) j++;
    A[i] = j;
    if (j == 0){
      i++; continue;
    }
    int k = 1;
    while (i + k < t && k + A[k] < j){
      A[i + k] = A[k]; k++;
    }
    i += k; j -= k;
  }

  for (int i = 0; i <= t; i++){
    ans = max(ans, min(i, A[i]));
  }

  return 0;
}

int main(){
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    T = S.substr(i, N);
    Solve();
  }
  cout << ans << endl;

  return 0;
}
