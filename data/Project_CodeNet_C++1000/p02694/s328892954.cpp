#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t x, yokin = 100LL, year = 0LL;
  cin >> x;
  while(yokin < x) {
    yokin += yokin / 100LL;
    year++;
  }
  cout << year;
}