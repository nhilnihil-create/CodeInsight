#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {

  int n;
  cin >> n;

  int num;
  bool finished = false;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      num = i * j;

      if (num == n) {
        finished = true;
        break;
      }
    }
    if (finished == true) {
      break;
    }
  }

  if (finished == true) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}