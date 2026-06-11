#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 5010;
int d[N];
int dm[N];
int zero[N];
ll sum[N];
int n, x, m;

int k, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> q;
    for (int i = 0; i < k; ++i) {
      cin >> d[i];
    }
    // query
    for (int i = 0; i < q; ++i) {
      cin >> n >> x >> m;
      // seq: x, x + d0 , x + d0 + d1, x + d.....
      // find aj % m < aj+1 % m
      // gt: aj / m + 1 == aj+1 / m
      // eq: d % k == 0, d % m == 0

      x %= m;
      sum[0] = 0, zero[0] = 0;
      for (int j = 0; j < k; ++j) {
        dm[j] = d[j] % m;
        sum[j + 1] = sum[j] + dm[j];
        zero[j + 1] = zero[j] + (dm[j] == 0);
      }
      int a = (n - 1) / k * zero[k] + zero[(n - 1) % k];
      int b = ((n - 1) / k * sum[k] + sum[(n - 1) % k] + x) / m - x / m;
      int ans = (n - 1) - a - b;
      cout << ans << endl;
    }

    return 0;
}
