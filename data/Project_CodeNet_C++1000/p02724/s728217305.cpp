#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  int tmp = x / 500;
  int tmp_2 = x % 500;
  int tmp_3 = tmp_2 / 5;
  int total = 1000 * tmp + 5 * tmp_3;
  cout << total << endl;
  return 0;
}