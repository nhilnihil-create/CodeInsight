#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  vector<pli> v(N);

  for(int i = 0; i < N; i++){
    ll tmp;
    cin >> tmp;
    v[i] = make_pair(tmp, i);
  }

  sort(v.rbegin(), v.rend());

  // dp[i][j]: 左にi個, 右にj個詰めた時の最大値
  vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));

  for(ll i = 0; i < N; i++){
    ll pos = v[i].second;
    ll val = v[i].first;
    for(int x = 0; x <= i; x++){
      int y = i - x;
      dp[x+1][y] = max(dp[x+1][y], dp[x][y] + abs(x-pos) * val);
      dp[x][y+1] = max(dp[x][y+1], dp[x][y] + abs(N-y-1-pos) * val);
    }
  }

  ll max_val = 0;
  for(int i = 0; i <= N; i++){
    // cerr << i << " " << N-i << " " << dp[i][N-i] << endl;
    max_val = max(max_val, dp[i][N-i]);
  }
  cout << max_val << endl;

}
