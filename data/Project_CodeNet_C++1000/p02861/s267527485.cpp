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

int N;
double X[10], Y[10];

double dist(int i, int j){
  double ans = (X[i] - X[j]) * (X[i] - X[j]);
  ans += (Y[i] - Y[j]) * (Y[i] - Y[j]);
  return sqrt(ans);
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  double ans = 0;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      ans += dist(i, j);
    }
  }
  ans *= 2;
  ans /= (double) N;

  cout << setprecision(64) << ans << endl;

  return 0;
}
