#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  ll X;
  cin >> X;

  for (int i = -200; i <= 200; i++) {
    for (int j = -200; j <= 200; j++) {
      if (pow(i, 5) - pow(j, 5) == X) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}