#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#define debug(x) cout << #x << "==" << x << endl;

using namespace std;

const int INF = 1e+8;

//??\???
#define MAX_N 50000
#define MAX_M 20
int N;
int M;
int C[MAX_M];

// dp ????????????
int dp[MAX_N + 1];
bool checked[MAX_N + 1];


int least_coins(int s) {

  if(s < 0) { return INF; }
  if(checked[s] == true) { return dp[s]; }
  if(s == 0) { return 0; }

  int mn = INF;
  for(int i = 0; i < M; i++) {
    mn = min( mn, least_coins( s - C[i] ) + 1 );
  }

  checked[s] = true;
  return dp[s] = mn;

}

int main() {
  ios::sync_with_stdio(false);

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    cin >> C[i];
  }

  cout << least_coins(N) << endl;

  return 0;

}