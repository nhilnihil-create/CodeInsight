#include<bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  if (x==2) {
    cout << x << endl;
    return 0;
  }
  while (true) {
    bool a = 0;
    for (int i = 2; i<=sqrt(x); i++) {
      if (x%i==0) {
        a = 1;
        x++;
        break;
      }
    }
    if (a==0) {
      cout << x << endl;
      return 0;
    }
  }
}