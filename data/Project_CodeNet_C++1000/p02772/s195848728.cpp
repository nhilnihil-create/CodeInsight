#include <bits/stdc++.h>
#define ll long long
#define rep(i, n)(for i=0;i<n;++i);
using namespace std;
int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }
const double PI = 3.14159265358979323846;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      if (a[i] % 3 != 0 && a[i] % 5 != 0) {
        cout << "DENIED";
        return 0;
      }
    }
  }
  cout << "APPROVED";
}