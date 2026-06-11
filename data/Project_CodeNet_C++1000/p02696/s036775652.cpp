#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  ll A, B, N;
  cin >> A >> B >> N;

  // floor(Ax/B) - A*floor(x/B)
  // 左と右の差が答えであり最大値を求める
  // A=6 B=2 x=3で計算してみると
  // floor(6*3/2)=9 と 6*floor(3/2) = 6 の差は3
  // 3というのは、floor(3/2)でで切り捨てられている部分を6倍したもの
  // 切り捨てられている部分は3%2/2で求められる
  // x%Bを大きくすると結果も最大になる
  // x%Bは最大でもB-1、制約としてx<=N
  // x%Bの最大値numをBで割ってA倍してfloor
  ll num = min(B - 1, N);
  ll ans = floor((double)num / (double)B * (double)A);
  cout << ans << endl;
  
  return 0;
}