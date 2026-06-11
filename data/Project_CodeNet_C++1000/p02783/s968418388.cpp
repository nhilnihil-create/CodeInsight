#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int h, a;
  cin >> h >> a;
  cout << (h / a) + ((h % a == 0) ? 0 : 1) << endl;
  return 0;
}
