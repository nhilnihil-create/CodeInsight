#include <bits/stdc++.h>
using namespace std;

int64_t attack(int64_t hp) {
  if (hp == 1) {
    return 1;
  }
  return 1 + 2*attack(hp/2);
}
 
int main() {
  int64_t h, min;
  cin >> h;
  min = attack(h);
  cout << min << endl;
}