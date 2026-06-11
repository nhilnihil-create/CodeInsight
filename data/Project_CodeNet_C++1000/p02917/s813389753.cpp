#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, s, b1, b2;
  cin >> n >> b1;
  s = b1;
  for(int i = 1;i < n-1;i++) {
    cin >> b2;
    s += min(b1, b2);
    b1 = b2;
  }
  s += b1;
  cout << s << endl;
}