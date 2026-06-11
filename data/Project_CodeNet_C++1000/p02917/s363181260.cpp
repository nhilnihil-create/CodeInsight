#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> b(n-1), a(n);
  rep(i, 0, n-1) cin >> b[i];
  a[0] = b[0];
  rep(i, 0, n-1) {
    if(b[i] < a[i]) a[i] = b[i];
    a[i+1] = b[i];
  }
  int sum = 0;
  rep(i, 0, n) sum += a[i];
  cout << sum << "\n";
}