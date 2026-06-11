#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int x;
  cin >> x;
  
  int a = x / 100;
  int b = x % 100;
  
  bool ok = false;
  for (int i = 0; i <= 5*a; i++) {
    if (i == b) ok = true;
  }
  if (ok)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}
