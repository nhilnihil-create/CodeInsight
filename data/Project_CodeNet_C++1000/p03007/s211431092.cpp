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

int N; ll A[int(1e5+5)];
vector <Pll> ans;

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);

  ll M = 0;
  if (A[N-1] < 0){
    M = A[N-1];
    for (int i = 0; i < N - 1; i++){
      ans.push_back({M, A[i]});
      M -= A[i];
    }
  }else if (A[0] > 0){
    M = A[0];
    for (int i = 1; i < N - 1; i++){
      ans.push_back({M, A[i]});
      M -= A[i];
    }
    ans.push_back({A[N-1], M});
    M = A[N-1] - M;
  }else{
    M = A[0];
    for (int i = 1; i < N - 1; i++){
      if (A[i] < 0){
        ans.push_back({A[N-1], A[i]});
        A[N-1] -= A[i];
      }else{
        ans.push_back({M, A[i]});
        M -= A[i];
      }
    }
    ans.push_back({A[N-1], M});
    M = A[N - 1] - M;

  }

  cout << M << endl;
  for (int i = 0; i < N - 1; i++){
    cout << ans[i].fi << " " << ans[i].se << endl;
  }

  return 0;
}
