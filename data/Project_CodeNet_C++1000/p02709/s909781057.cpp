#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include<limits>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const long double pi = 3.141592653589793;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define F first
#define S second

// #define COMMENT

/*

const int NN = 200090;
ll fact[NN];
ll finv[NN];
ll inv[NN];

void inverse_modulao() {
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(int i = 2;i < NN;i++) {
    fact[i] = fact[i-1]*i%mod;
    inv[i] = mod-mod/i*inv[mod%i]%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll nCr(int n, int r) {
  return fact[n]*finv[r]%mod*finv[n-r]%mod;
}

*/

ll N, dp[2022][2022];
vector<pair<ll,int>> A(1<<20);

int main() {

//  freopen("input.in","r",stdin);
//  freopen("output.out","w",stdout);

  cin >> N;
  rep(i, N) {
    cin >> A[i].F;
    A[i].S = i;
  }
  // debug(N);
  sort(A.begin(),A.begin()+N);
  rep(i,N) {
    for(int j = 0;j < N-i;j++) {
      if(i==0) {
        dp[i][j]=abs(j-A[i].S)*A[i].F;continue;
      }

      ll u = abs(j-A[i].S)*A[i].F + dp[i-1][j+1];
      ll v = abs(i+j-A[i].S)*A[i].F + dp[i-1][j];
      dp[i][j] = max(u, v);
    }
  }

  cout << dp[N-1][0] << endl;

  return 0;
}
