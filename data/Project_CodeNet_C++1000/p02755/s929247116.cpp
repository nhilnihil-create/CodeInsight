#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  for(int i = 1; i <= 1450; i++) {
    int ta = i*8/100;
    int tb = i*10/100;
    if(ta == a && tb == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}