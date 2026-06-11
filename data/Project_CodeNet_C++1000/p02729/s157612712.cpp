#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  int x = n * (n - 1) / 2;
  int y = m * (m - 1) / 2;
  cout << x + y << endl;
}