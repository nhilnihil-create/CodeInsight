#include <iostream>
using namespace std;

int main() {
  int S, hour, minute, second;
  cin >> S;

  hour = S / 3600;
  S %= 3600;
  minute = S / 60;
  S %= 60;
  second = S;

  cout << hour << ":" << minute << ":" << second << endl;
}