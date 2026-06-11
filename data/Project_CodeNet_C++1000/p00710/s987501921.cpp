#include <iostream>

using namespace std;

int cards[51];

void cut_operation(int p, int c) {
  int tmp[51];
  int tmp2[51];
  for (int i = 0; i < p - 1; i++)  {
    tmp[i] = cards[i];
  }
  for (int i = 0; i < c; i++) {
    tmp2[i] = cards[p - 1 + i];
  }
  for (int i = 0; i < c; i++)  {
    cards[i] = tmp2[i];
  }
  for (int i = 0; i < p - 1; i++) {
    cards[i + c] = tmp[i];
  }
}

int main() {
  int n, r;
  while (true) {
    cin >> n >> r;
    if (n + r == 0) break;
    for (int i = 0; i < 51; i++) {
      cards[i] = n - i;
    }
    for (int i = 0; i < r; i++) {
      int p, c;
      cin >> p >> c;
      cut_operation(p, c);
    }
    cout << cards[0] << endl;
  }
  
  return 0;
}