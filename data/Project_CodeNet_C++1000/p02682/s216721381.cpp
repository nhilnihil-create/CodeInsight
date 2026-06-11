#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {

  long long a, b, c, k;
  cin >> a >> b >> c >> k;

  if (k <= a) cout << k << endl;
  else if (k <= a + b) cout << a << endl;
  else cout << a-(k-a-b) << endl;

}