#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n%2==0) {
    cout << 0.5 << endl;
  }
  else {
    cout << (double)(n+1)/(2*n) << endl;
  }
}