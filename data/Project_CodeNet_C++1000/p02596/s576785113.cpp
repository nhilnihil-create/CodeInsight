#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int K;
  cin >> K;
  int wk = 0;
  int multiply = 1;    
  rep(i,K+10) {
    wk += 7 * multiply;
    if (wk % K == 0) {
      cout << i+1 << endl;
      return 0;
    }      
    wk %= K;
    multiply = multiply * 10 % K;
  }
  cout << -1 << endl;
  return 0;
}