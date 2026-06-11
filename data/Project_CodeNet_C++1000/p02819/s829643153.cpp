#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int X;
  cin >> X;
  if(X == 2 || X == 3 || X == 5 || X == 7) {
    cout << X << endl;
  }
  else {
    bool finished = false;
    if(X % 2 == 1) {
      for(long long int i = X; true; i += 2) {
        for(long long int j = 3; j * j <= i; j += 2) {
          if(i % j == 0) {
            break;
          }
          if((j + 2) * (j + 2) > i && i % j != 0) {
            finished = true;
            cout << i << endl;
          }
        }
        if(finished) {
          break;
        }
      }
    }
    else {
      for(long long int i = X + 1; true; i += 2) {
        for(long long int j = 3; j * j <= i; j += 2) {
          if(i % j == 0) {
            break;
          }
          if((j + 2) * (j + 2) > i && i % j != 0) {
            finished = true;
            cout << i << endl;
          }
        }
        if(finished) {
          break;
        }
      }
    }
  }
}