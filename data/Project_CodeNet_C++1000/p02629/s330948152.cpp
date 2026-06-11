#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;

  string res;
  while (n > 0) {
    res = char('a' + --n % 26) + res;
    n /= 26;
  }
  cout << res << endl;
}
