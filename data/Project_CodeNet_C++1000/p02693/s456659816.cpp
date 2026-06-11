#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int k, a, b;
  cin >> k >> a >> b;
  for(int i = a; i <= b; i++) {
    if(i % k == 0) {
      cout << "OK";
      return 0;
    }
  }
  cout << "NG";
}
