#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int x = 0;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  vector<int> b(n, 0);
  for (int i = 0; i < n; i++) {
   b[a[i]]++;
  }
  for (int i = 1; i < n; i++) {
    cout << b[i] << endl;
  }
  cout << x << endl;
}
