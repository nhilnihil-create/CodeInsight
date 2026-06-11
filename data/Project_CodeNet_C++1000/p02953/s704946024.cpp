#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n, a, m;
  bool c = true;
  cin >> n >> m;
  rep(i, n-1) {
    cin >> a;
    if(a-m<-1) {
      c = false;
      break;
    } else if(a > m) {
      m = a;
    }
  }
  cout << (c ? "Yes" : "No") << endl;
}