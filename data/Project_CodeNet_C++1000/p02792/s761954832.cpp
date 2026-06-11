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

int N;
ll DP[10][10];

int Solve(int num){
  int j = num % 10;
  while (num >= 10) num /= 10;
  DP[num][j]++;
  return 0;
}

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) Solve(i);

  ll ans = 0;
  for (int i = 1; i <= 9; i++){
    for (int j = 1; j <= 9; j++){
      ans += DP[i][j] * DP[j][i];
    }
  }
  cout << ans << endl;

  return 0;
}
