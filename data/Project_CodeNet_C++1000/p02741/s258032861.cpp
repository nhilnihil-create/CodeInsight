#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int K;
  cin >> K;
  int a[] = {1, 1, 1, 2, 1, 2, 1, 5,  2, 2, 1, 5, 1, 2, 1, 14,
             1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

  cout << a[K - 1] << endl;
  return 0;
}