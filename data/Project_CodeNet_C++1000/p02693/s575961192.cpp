#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  bool check = false;
  if((a % k) == 0 || (b % k) == 0) check = true;
  else {
    int x = a / k;
    if(k * (x + 1) < b) {
      check = true;
    }
  }
  if(check) cout << "OK" << endl;
  else cout << "NG" << endl;
}