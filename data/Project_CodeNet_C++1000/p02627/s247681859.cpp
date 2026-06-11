#include <iostream>
using namespace std;
int main() {
  char c;
  cin >> c;
  if ('a' <= c && c <= 'z')
    cout << "a";
  else
    cout << "A";
  return 0;
}