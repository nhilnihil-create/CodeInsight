#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  ll ans = 100;
  ll year = 0;
  while(x > ans) {
    ll tmp = ans / 100;
    ans += tmp;
    year++;
  }
  
  cout << year << endl;
}
