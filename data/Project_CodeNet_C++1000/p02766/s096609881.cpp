#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int c = 1;
  while (n >= k) {
    n /= k;
    c++;
  }
  cout << c << endl;   
}