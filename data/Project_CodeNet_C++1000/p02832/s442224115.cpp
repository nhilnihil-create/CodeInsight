#include <iostream>

using namespace std;

int main() {
  int N, a, c{1};
  cin >> N;
  while (cin >> a) if (a == c) ++c;
  cout << (c == 1 ? -1 : N - c + 1) << endl;
}
