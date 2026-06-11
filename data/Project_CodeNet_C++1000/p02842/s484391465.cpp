#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;
  float tax = 1.08;
  int price = 0;
  while (price * tax < N + 1) {
    price++;
    if (N <= price * tax && price * tax < N + 1) {
      cout << price;
      break;
    }
    if (price * tax >= N + 1) {
      cout << ":(";
      break;
    }
  }
}
