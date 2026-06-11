#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <iomanip>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int ctz(int x) { return __builtin_ctz(x); }
int clz(int x) { return __builtin_clz(x); }

const int maxn = 2005;
int dp[maxn][maxn];
int a[maxn], b[maxn];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> b[i];
  }
  dp[0][0] = 1;
  vector <vi> pfsm(n + 1, vi(m + 1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i] == b[j]){
        dp[i][j] = add(dp[i][j], pfsm[i - 1][j - 1]);
        dp[i][j] = add(dp[i][j], 1);
      }
      pfsm[i][j] = dp[i][j];
      pfsm[i][j] = add(pfsm[i][j], add(pfsm[i][j - 1], pfsm[i - 1][j]));
      pfsm[i][j] = sub(pfsm[i][j], pfsm[i - 1][j - 1]);
    }
  }
  int res = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      res = add(res, dp[i][j]);
    }
  }
  cout << res; 
}