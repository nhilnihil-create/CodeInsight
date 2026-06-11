#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  --k;
  int s[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  cout << s[k] << '\n';
  return 0;
}
