#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n, x, l, s = 1, p = 0;
  cin >> n >> x;
  rep(i, n) {
    cin >> l;
    if(p + l <= x) {
      s++;
      p += l;
    } else {
      break;
    }
  }
  cout << s << endl;
}
