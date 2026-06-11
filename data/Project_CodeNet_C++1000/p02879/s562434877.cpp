#include <iostream>
using namespace std;
int main() {
  int n,m;
  cin >> n >> m;
  if (n <= 9 && m <= 9) cout << n*m << endl;
  else cout << -1 << endl;
}