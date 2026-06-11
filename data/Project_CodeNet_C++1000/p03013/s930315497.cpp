#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const long long mod = 1e9+7;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  vector<int> oks(N+1, true);
  for(int i = 0; i < M; i++) {
    int a;
    cin >> a;
    oks[a] = false;
  }

  vector<long long int> dp(N+1);
  dp[0]=1;
  for(int now=0; now<N; ++now) {
    for(int next=now+1; next<=min(N,now+2); ++next) {
      if(oks[next]) {
        dp[next] += dp[now];
        dp[next] %= mod;
      }
    }
  }

  cout << dp[N] << endl;

  return 0;
}
