#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  cin >> n >> m;

  int total_votes = 0;
  vector<int> items;

  rep(i, n) {
    int a;
    cin >> a;
    total_votes += a;
    items.push_back(a);
  }

  sort(items.begin(), items.end(), greater<int>());

  double threshold = total_votes * (1.0 / (4 * m));

  if (items[m - 1] >= threshold) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
