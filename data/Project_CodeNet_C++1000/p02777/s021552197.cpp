#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  int a, b;
  string C;
  cin >> A >> B >> a >> b >> C;
  if(A == C) {
    cout << a - 1 << " " << b << endl;
  }
  else {
    cout << a << " " << b - 1 << endl;
  }
}
