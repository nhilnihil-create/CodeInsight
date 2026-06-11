#include <bits/stdc++.h>
using namespace std;

int main() {
  int X; cin >> X;
  int tmp = X;
  int ans =0;
  bool check = false;
  while (!check) {
    int count =0;
    for (int i =2; i<tmp; i++) {
      if (tmp % i != 0) count++;
    }
    if (count == tmp - 2) {
      ans = tmp;
      check = true;
    } else {
      tmp++;
    }
  }
  cout << ans << endl; 
}