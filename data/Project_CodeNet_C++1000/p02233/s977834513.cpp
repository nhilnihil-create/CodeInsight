#include <iostream>
using namespace std;

const int MAX = 44;
int MEM[MAX];

int fibonacci(int i) {
  if (MEM[i] != -1) return MEM[i];
  if (i == 0 || i == 1) return 1;
  MEM[i - 2] = fibonacci(i - 2);
  MEM[i - 1] = fibonacci(i - 1);
  return MEM[i - 2] + MEM[i - 1];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  for (int i = 0; i <= MAX; i++) MEM[i] = -1;

  int i;
  cin >> i;

  cout << fibonacci(i) << endl;

  return 0;
}