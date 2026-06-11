#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int n, m, a=0;
  cin >> n >> m;
  rep(i, m) {
    int t;
    cin >> t;
    a += t;
  }
  n >= a ? cout << n - a : cout << -1;
}
