#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, s = 0;
  cin >> n;
  for(int i = 1;i <= n;i++) {
    cin >> a;
    if(a != i) s++;
  }
  cout << ((s == 0 || s == 2) ? "YES" : "NO") << endl;
}