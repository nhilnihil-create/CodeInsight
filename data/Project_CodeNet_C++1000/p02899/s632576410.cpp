#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<pair<int,int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(all(a));
  for (int i = 0; i < n; i++) {
    cout << a[i].second << (i < n - 1 ? ' ' : '\n');
  }
  return 0;
}