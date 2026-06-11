#include <bits/stdc++.h>
using namespace std;
int main() {
// Your code here!
  long long a, b, c;
  cin >> a >> b >> c;
  int x = 0;
  if (a+b<c) {
    if (4 * a*b < (c - a - b)*(c - a - b)) {
      cout<<"Yes" << endl;
      x++;
    }
  }
  if (x == 0) {
  cout << "No" << endl;
  }
}