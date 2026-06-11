#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll money = 100;
  ll X;
  cin >> X;
  ll count = 0;
  while (money < X) {
    money = money + money / 100;
    count++;
  }
  cout << count << endl;
  return 0;
}