#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll x;
  cin >> x;
  int year = 0;
  ll money = 100;
  while(money < x) {
    money += money / 100;
    year++;
  }
  cout << year;
}
