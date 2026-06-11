#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long res = 0;
  res += (N / 500) * 1000;
  N %= 500;
  res += (N / 5) * 5;
  cout << res << endl;
}