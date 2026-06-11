#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b;
  cin >> a >> b;
  bool flag = true;
  if( !(1 <= a && a <= 9) || !(1 <= b && b <= 9)) {
    flag = false;
  }
  
  if(flag) cout << a*b << endl;
  else cout << -1 << endl;
}