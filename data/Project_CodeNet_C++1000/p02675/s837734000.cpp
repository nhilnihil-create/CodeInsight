#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
  int N;
  cin >> N;
  int a = N % 10;
  if (a == 3) {
    cout << "bon" << endl;
  } else if (a == 0 || a == 1 || a == 6 || a == 8) {
    cout << "pon" << endl;
  } else {
    cout << "hon" << endl;
  }
  return 0;
}