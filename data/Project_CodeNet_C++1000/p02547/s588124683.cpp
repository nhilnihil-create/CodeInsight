#include <iostream>

using namespace std;

int main() {
  int N, D1, D2, c{}, f{};
  cin >> N;
  while(cin >> D1 >> D2) {
    if (D1 == D2) ++c;
    else c = 0;
    if (c >= 3) {
      f = 1;
      break;
    }
  }
  cout << (f ? "Yes" : "No") << endl;
}
