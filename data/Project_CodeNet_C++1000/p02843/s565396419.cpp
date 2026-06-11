#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a;
  b = a%100;
  a /= 100;
  if(b<=a*5) cout << 1;
  else cout << 0;
}