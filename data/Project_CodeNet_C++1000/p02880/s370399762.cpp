#include <bits/stdc++.h>
using namespace std;

#define Yes_Or_No(flag) if (flag) \
  { cout << "Yes" << endl; } \
  else \
  { cout << "No" << endl; }

int main() {
  int N;
  cin >> N;
  
  bool flag = false;
  
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if ((i * j) == N) {
        flag = true;
      }
    }
  }

  Yes_Or_No(flag);
}