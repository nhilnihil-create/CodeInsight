#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int x[5];
  rep (i, 5) {
    cin >> x[i];
    if (x[i] == 0) cout << i+1 << endl;
  }
  return 0;
}