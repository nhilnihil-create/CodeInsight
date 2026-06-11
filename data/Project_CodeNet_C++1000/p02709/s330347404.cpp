#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

using ll = long long int;
using namespace std;

int main(){
  
  // read problem
  ll N, tmp;
  vector<pair<ll,ll> > A;

  cin >> N;
  for(ll i = 0; i < N; i++){
    cin >> tmp;
    A.push_back(make_pair(tmp, i));
  }

  sort(A.begin(), A.end(), greater<pair<ll,ll> > ());

  cerr << "A: " << endl;
  for(ll i = 0; i < N; i++){
    cerr << A[i].first << " ";
  }cerr << endl;

  // solve problem
  vector<vector<ll> > dp(N+1, vector<ll>(N+1));

  for(ll i = 1; i <= N; i++){
    dp[i][0] = dp[i-1][0] + A[i-1].first*(A[i-1].second - (i-1));
    dp[0][i] = dp[0][i-1] + A[i-1].first*(N-i - A[i-1].second);
  }

  for(ll i = 1; i <= N; i++){
    for(ll j = 1; j <= N; j++){
      if(i+j>N){
        continue;
      }
      dp[i][j] = max(dp[i-1][j] + A[i+j-1].first*(A[i+j-1].second - (i-1)), dp[i][j-1] + A[i+j-1].first*(N-j-A[i+j-1].second));
    }
  }

  ll ans = 0;
  for(ll i = 0; i <= N; i++){
    ans = max(ans, dp[i][N-i]);
  }
  
  cerr << "Answer: " << endl;
  cout << ans << endl;

  return 0;


}
