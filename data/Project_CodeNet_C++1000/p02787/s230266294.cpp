#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

vector<ll> memo(51, 0);

int 
main()
{
  int H, N; cin >> H >> N;
  vector<pair<int, int>> magic(N);
  rep(i, 0, N) cin >> magic[i].first >> magic[i].second;
  vector<vector<ll>> dp(N + 1, vector<ll>(H + 1, 0));
  rep(h, 1, H + 1){
    if(h / magic[0].first < 1){
      dp[0][h] = magic[0].second;
    } else if(h % magic[0].first == 0) {
      dp[0][h] = (h / magic[0].first) * magic[0].second;
    } else {
      dp[0][h] = (floor(h / magic[0].first) + 1) * magic[0].second;
    }
  }
  rep(i, 1, N){
    rep(h, 0, H + 1){
      if(h / magic[i].first < 1){
        dp[i][h] = magic[i].second;
      } else if(h % magic[i].first == 0) {
        dp[i][h] = (h / magic[i].first) * magic[i].second;
      } else {
        dp[i][h] = (floor(h / magic[i].first) + 1) * magic[i].second;
      }
      if(dp[i][h] > dp[i - 1][h]) dp[i][h] = dp[i - 1][h];
      if(h - magic[i].first >= 0){
        if(dp[i][h] > magic[i].second + dp[i][h - magic[i].first]) dp[i][h] = magic[i].second + dp[i][h - magic[i].first];
      }
    }
  }

  cout << dp[N - 1][H] << endl;

}