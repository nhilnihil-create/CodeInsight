#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  bool flag = false;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      if(n == i * j) flag = true;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}