#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll H, I = 0;
  cin >> H;
  while(true) {
    if (H == 1) {
      I++;
      break;}
    else {
      I++;
      I *= 2;
      H /= 2;
    }
  }
  cout << I << endl;
}