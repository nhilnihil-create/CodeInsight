#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  bool flag = true;
  rep(i, n) {
    int a;
    cin >> a;
    if(a % 2 == 0) {
      if(!(a % 3 == 0 || a % 5 == 0)) flag = false;
    }
  }
  if(flag) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
  return 0;
}