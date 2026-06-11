#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, perm, ans = 0;
  cin >> n >> perm;
  cout << n / (perm * 2 + 1) + (n % (perm * 2 + 1) != 0);
  return 0;
}
