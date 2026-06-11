#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, c = 1;
  cin >> n >> k;
  int K = k;
  while(K <= n) {
    K *= k;
    c++;
  }
  cout << c << endl;
}