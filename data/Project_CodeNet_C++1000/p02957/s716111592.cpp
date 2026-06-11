#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  (a+b)%2 ? cout << "IMPOSSIBLE" : cout << (a+b)/2;
}
