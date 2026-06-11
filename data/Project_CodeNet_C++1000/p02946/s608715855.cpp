#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int k, x;
  cin >> k >> x;
  int tmp = x - k + 1;
  int tmp_2 = x + k - 1;
  for(int i = tmp; i <= tmp_2; i++) {
    cout << i << " ";
  }
  cout << endl;
}