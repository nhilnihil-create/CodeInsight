#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  rep(i, 1300) {
    if(i * 8 / 100 == a && i / 10 == b) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
}
