#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t X;
  cin >> X;
  int y = 0;
  int64_t money = 100LL;
  while (money < X) {
    money += money / 100LL;
    y++;
  }
  cout << y << endl;
}