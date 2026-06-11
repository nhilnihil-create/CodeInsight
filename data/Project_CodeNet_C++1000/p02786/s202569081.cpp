#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
ll counter(ll N){
  if(N == 1){
    return 1;
  }
  return 1 + 2 * counter(N / 2);
}
int main() {
  ll H;
  cin >> H;
  cout << counter(H) << endl;
  return 0;
}