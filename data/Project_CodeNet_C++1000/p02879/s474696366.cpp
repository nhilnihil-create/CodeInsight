#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;


int main() {
  int a,b;
  cin >> a >> b;
  if (0 <= a && a <= 9 && 0 <= b && b <= 9) {
    cout << a * b << endl;
  } else {
    cout << -1 << endl;
  }
}
