#include <bits/stdc++.h>
using namespace std;
int main () {
  int X;
  cin >> X;
  long ans = 1;
  while((X * ans) % 360 != 0){
    ans++;
  }
  cout << ans << endl;
  return 0;
}