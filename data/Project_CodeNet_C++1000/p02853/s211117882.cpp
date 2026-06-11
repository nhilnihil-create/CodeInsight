#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x, y;
  cin >> x >> y;
  int n = 0;
  if(x == 1)n += 300000;
  if(y == 1)n += 300000;
  if(x == 2)n += 200000;
  if(y == 2)n += 200000;
  if(x == 3)n += 100000;
  if(y == 3)n += 100000;
  if(x == y){
    if(x == 1)n += 400000;
  }
  cout << n << endl;
}