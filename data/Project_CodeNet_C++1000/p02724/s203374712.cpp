#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1'000'000'000;

int main() {
  int x;
  cin >> x;
  int a = x / 500 * 1000;
  int b = x % 500 / 5 * 5;
  cout << a + b << endl;
}
