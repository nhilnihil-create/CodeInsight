#include <bits/stdc++.h>
using namespace std;

int main() {
  int y;
  cin >> y;
  y %= 1000;
  if(y != 0) 
    y = 1000 - y;
  cout << y << endl;
}