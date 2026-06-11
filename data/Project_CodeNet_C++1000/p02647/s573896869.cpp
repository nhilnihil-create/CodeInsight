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

int N, K;
int A[int(2e5+5)], B[int(2e5+5)];

int main(){
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];

  for (int i = 0; i < K; i++){
    fill(B, B + N, 0);

    for (int j = 0; j < N; j++){
      int m = max(0, j - A[j]);
      int M = min(N, j + A[j]) + 1;

      B[m]++; B[M]--;
    }
    for (int j = 1; j < N; j++){
      B[j] += B[j-1];
    }

    bool flag = true;
    for (int j = 0; j < N; j++){
      if (A[j] != B[j]) flag = false;
    }

    if (flag) break;
    for (int j = 0; j < N; j++) A[j] = B[j];
  }

  cout << A[0];
  for (int i = 1; i < N; i++) cout << " " << A[i];
  cout << endl;


  return 0;
}
