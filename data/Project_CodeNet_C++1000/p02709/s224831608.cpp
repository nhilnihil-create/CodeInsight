#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;

long long MOD = 10000000000 + 7;

bool compare(plli x, plli y){
  return x.first > y.first;
}

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<plli> v(N);

  for(int i = 0; i < N; i++){
    ll tmp;
    cin >> tmp;
    v.at(i) = make_pair(tmp, i);
  }

  sort(v.begin(), v.end(), compare);

  // cerr << v[0].first << " " << v[0].second << endl;

  vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0)); 
  // dp[i][j] : 左にi個、右にj個入れたときの最大
  for(int k = 1; k <= N; k++){
    // dp[i][j]: i+j = k を走査する
    for(int i = 0; i <= k; i++){
      int j = k - i;
      if(i-1>=0) dp[i][j] = max(dp[i][j], dp[i-1][j] + v[k-1].first * abs(v[k-1].second - i + 1) );
      if(j-1>=0) dp[i][j] = max(dp[i][j], dp[i][j-1] + v[k-1].first * abs(N-j - v[k-1].second));
    }
  }
  ll ans = 0;
  for(int i = 0; i <= N; i++){
    ans = max(ans, dp.at(i).at(N-i));
  }
  cout << ans << endl;
}
