#include <bits/stdc++.h>
using namespace std;
int main () {
  int q, p ,r;
  cin >> q >> p >>r;
  int x= q+p;
  int y = p +r;
  int e = r +q;
  cout << min( e, min (x, y)) ;}