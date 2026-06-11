#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;

bool IsPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
      if (num % i == 0){
        // 素数ではない
        return false;
      }
    }
    // 素数である
    return true;
}

int main(){
  int x; cin >> x;
  int ans = 0;

  while(true){
    if(IsPrime(x)) break;
    x++;
  }
  cout << x << endl;

  return 0;
}