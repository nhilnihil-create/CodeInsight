#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 1;
int n, k, q, t;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> q;
  for (int i = 1; i <= n; ++i) {
    a[i] = k - q;
  }
  for (int i = 0; i < q; ++i) {
    cin >> t;
    a[t]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}
