#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  if(a >= k) {
    cout << k << endl;
    return 0;
  }
  else if(a + b >= k) {
    cout << a << endl;
    return 0;
  }
  // a + b < k cを使う場合になる
  else {
    int max = a + -1*(k - a - b);
    cout << max << endl;
    return 0;
  }
}