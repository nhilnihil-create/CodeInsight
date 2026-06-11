#include <bits/stdc++.h>
typedef long long LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int S, W;
  cin >> S >> W;
  if (S <= W) {
    cout << "unsafe" << endl;
    return 0;
  }

  cout << "safe" << endl;
}
