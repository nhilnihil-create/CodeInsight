#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}


int dp[(int)1e5+1][13];

int MOD = 1e9+7;

int main(){
  string S;
  cin >> S;
  int N = sz(S);
  reverse(S.begin(), S.end());
  if(S[0] == '?'){
    rep(i, 10){
      dp[0][i] = 1;
    }
  }else{
    int idx = S[0] - '0';
    dp[0][idx] = 1;
  }

  int num = 1;
  for(int i=1; i<N; i++){
    num *= 10;
    num %= 13;
    if(S[i] == '?'){
      rep(k, 13){
        rep(j, 10){
          int r = (j*num + k) % 13;
          dp[i][r] += dp[i-1][k];
          dp[i][r] %= MOD;
        }
      }
    }else{
      rep(k, 13){
        int j = S[i] - '0';
        int r = (j*num + k)%13;
        dp[i][r] += dp[i-1][k];
        dp[i][r] %= MOD;
      }
    }
  }

  cout << dp[N-1][5] << endl;

  return 0;
}
