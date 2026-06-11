#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int A, B;
  cin >> A >> B;

  int tmp = 1;  //現在の未使用の差込口の数
  int ans = 0;  //使った電源タップの数
  while (true){
    if (tmp >= B) break;
    tmp += A - 1;
    ans ++;
  }
  cout << ans << endl;
}
