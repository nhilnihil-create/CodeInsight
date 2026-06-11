#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
int n;
cin >> n;
if (n == 1) cout << 1 << endl;
else if (n%2 == 0) {
  double a = n/2;
  cout << a/n  << endl;
} else {
  double a = n/2+1;
  cout << a/n << endl;
}
return 0;
}

