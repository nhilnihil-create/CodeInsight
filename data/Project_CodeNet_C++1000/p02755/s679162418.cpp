#include <bits/stdc++.h>
using namespace std;

int x() {
  int a, b;
  cin >> a >> b;
  for(int i = 1;i < 1009;i++) {
    if((int)(i * 0.08) == a && (int)(i / 10) == b) return i;
  }
  return -1;
}
int main() {
  cout << x() << endl;
}