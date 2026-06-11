#include<iostream>
using namespace std;

int N;

int digit_num(int x) {
  int d = 0;
  while (x > 0) {
    x /= 10; d++;
  }
  return d;
}

int main() {
  cin >> N;
  int c = 0;
  for (int i = 1; i <= N; i++) {
    c += digit_num(i) % 2;
  }
  cout << c << endl;
}