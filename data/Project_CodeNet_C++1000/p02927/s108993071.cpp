#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int count = 0;
  for (int j = 1; j <= n; j++) {
  for (int i = 1; i <= m; i++) {
   int a = i/10;
   int b = i%10;
    if (a >= 2 && b >= 2 && a*b==j) {
      count++;
    }
  }
  }
  cout << count << endl;
}