#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  int n = 1;
  int cnt = 0;
  while(n < b) {
    n += a-1;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}