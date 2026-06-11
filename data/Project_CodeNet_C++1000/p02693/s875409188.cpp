#include <iostream>

using namespace std;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  puts(b / k * k < a ? "NG" : "OK");
}
