#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 5100000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i=2; i<MAX; i++){
    fac[i] = fac[i-1]*i%MOD;
    inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
    finv[i] = finv[i-1]*inv[i]%MOD;
  }
}

// 二項係数計算
ll COM(int n, int k){
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main() {
  ll X, Y;
  cin >> X >> Y;
  // どうあがいても無理なとき
  if ((2*Y-X)%3!=0||(2*X-Y)%3!=0) {
    cout << 0 << endl;
    return 0;
  }
  COMinit();
  cout << COM((X+Y)/3, (2*X-Y)/3) << endl;
  return 0;
}