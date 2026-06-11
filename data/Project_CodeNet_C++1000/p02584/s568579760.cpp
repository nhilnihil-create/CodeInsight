#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll X,K,D;
  cin >> X >> K >> D;
  ll r = abs(X) % D;
  ll q = abs(X) / D;
  if(q > K){
    cout << abs(X) - K*D << endl;
    return 0;
  }
  if((K - q) % 2 == 0){
    cout << r << endl;
  }
  else{
    cout << D - r << endl;
  }
  return 0;
}

