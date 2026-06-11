#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;


int main() {
  int n;
  cin >> n;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (n == i * j) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
