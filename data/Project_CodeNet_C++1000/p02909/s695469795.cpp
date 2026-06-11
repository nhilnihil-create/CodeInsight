#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s == "Rainy") cout << "Sunny\n";
  else if (s == "Sunny") cout << "Cloudy\n";
  else cout << "Rainy\n";
  return 0;
}