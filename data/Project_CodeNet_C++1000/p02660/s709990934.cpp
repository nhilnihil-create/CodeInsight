// 素因数分解

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

int main(void){
  ll N;
  cin >> N;

  // 素因数とその肩に乗ってる指数のペア
  vector<pair<ll,int>> fs;
  for (ll i = 2; i*i <= N; i++){
    int x = 0;
    while (N%i == 0){
      N /= i;
      x++;
    }
    fs.emplace_back(i,x);
  }
  if (N != 1) fs.emplace_back(N,1);

  int ans = 0;
  for (auto p : fs){
    int x = p.second;
    int b = 1;
    while (b <= x){
      x -= b;
      b++;
      ans ++;
    }
  }
  cout << ans << endl;
  return 0;
}
