#include <iostream>

using namespace std;

int main() {
  string n;
  cin >> n;

  long long sum = 0;
  for (const char &c : n) sum += c - '0';
  puts(sum % 9 == 0 ? "Yes" : "No");
}
