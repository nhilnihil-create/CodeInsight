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

int N, A[20], X[20][20], Y[20][20];
int ans = 0;
bool now[20];

int Judge(int num){
  for (int i = 0; i < N; i++){
    if (num % 2 == 0) now[i] = false;
    else now[i] = true;
    num /= 2;
  }
  return 0;
}

int Solve(int num){
  Judge(num);

  for (int i = 0; i < N; i++){
    if (!now[i]) continue;
    for (int j = 0; j < A[i]; j++){
      int next = X[i][j];
      bool a = Y[i][j];
      if (now[next] != a) return 0;
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; i++){
    if (now[i]) cnt++;
  }
  ans = max(ans, cnt);

  return 0;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    for (int j = 0; j < A[i]; j++){
      cin >> X[i][j] >> Y[i][j];
      X[i][j]--;
    }
  }

  for (int i = 0; i < (1<<N); i++){
    Solve(i);
  }
  cout << ans << endl;

  return 0;
}
