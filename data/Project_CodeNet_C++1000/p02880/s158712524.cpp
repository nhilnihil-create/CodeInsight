#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool c = false;
  for(int i = 1;i < 10;i++) {
    if(n % i == 0 && n <= i * 9) c = true;
  }
  cout << (c ? "Yes" : "No") << endl;
}