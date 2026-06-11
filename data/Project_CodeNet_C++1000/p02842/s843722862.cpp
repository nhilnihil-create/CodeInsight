#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N;
  cin >> N;
  int X = ceil(N / 1.08);

  double XshouldBe = X * 1.08;
  if (floor(XshouldBe) == N) {
    cout << X << endl;
  } else {
    cout << ":(" << endl;
  }

  return 0;
}