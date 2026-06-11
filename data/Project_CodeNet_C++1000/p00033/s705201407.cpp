#include <iostream>
using namespace std;

int Balls[10];

bool fork(int balls[], int i, int b, int c) {
  if (i == 10) return true;
  if (b > balls[i] && c > balls[i]) return false;
  if (b < balls[i]) fork(balls, i + 1, balls[i], c);
  if (c < balls[i]) fork(balls, i + 1, b, balls[i]);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> Balls[j];
    }
    if(fork(Balls, 0, 0, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}