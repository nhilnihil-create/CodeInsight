#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main() {
  int a,b;
  cin >> a >> b;
  int x = a, y = b;
  for (int i = 1; i < b; i++) {

    x += a * pow(10,i);
  }
  for (int i = 1; i < a; i++) {
    y += b * pow(10,i);
  }

  if (to_string(x) < to_string(y)) cout << x << endl;
  else cout << y << endl;
}
