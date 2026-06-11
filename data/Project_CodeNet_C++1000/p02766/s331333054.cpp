#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N,K;
  cin >> N >> K;
  int d = 1;
  rep(i,36){
    if(N / d == 0){
      cout << i << endl;
      return 0;
    }
    d *= K;
  }
}