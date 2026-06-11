#include <iostream>

using namespace std;

int main()
{
  int n[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto &n1 : n)
    for (auto &n2 : n)
      cout << n1 << "x" << n2 << "=" << n1 * n2 << endl;
  return 0;
}