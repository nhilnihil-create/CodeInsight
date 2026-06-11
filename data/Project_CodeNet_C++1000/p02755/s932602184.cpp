#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int A,B;
  cin >> A >> B;
  for(int n = 1; n <= 1000;n ++){
    if(n * 8 / 100 == A && n * 10 / 100 == B){
      cout << n << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}