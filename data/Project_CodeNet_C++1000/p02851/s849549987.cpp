#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, k, t, sum;
ll res;
int temp[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  unordered_map<int, int> ma;
  ma[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (i >= k) {
      --ma[temp[i - k]];
    }
    cin >> t;
    sum = (sum + t - 1) % k;
    temp[i] = sum;
    if (ma.count(sum))
      res += ma[sum];
    ++ma[sum];
  }
  cout << res << endl;
  
  return 0;
}
