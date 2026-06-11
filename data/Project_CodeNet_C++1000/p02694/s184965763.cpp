#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long x;
  cin >> x;
  long year = 0;
  long money = 100;
  while (money < x) {
    year++;
    money +=money/100;
  }
  cout << year << endl;
  return 0;
}
