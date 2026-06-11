#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;

double calc(pii a, pii b) {
  double ans = pow(a.first - b.first, 2) + pow(a.second - b.second, 2);

  return sqrt(ans);
}

int fact(int a) {
  if (a == 0) return 1;

  return a * fact(a - 1);
}
int main() {
  int n;
  cin >> n;
  vector<pii> coord(n);

  for (int i = 0; i < n; i++) {
    cin >> coord[i].first >> coord[i].second;
  }

  double ans = 0;

  vector<int> permu;

  for (int i = 0; i < n; i++) {
    permu.push_back(i);
  }

  do {
    for (int i = 0; i < n - 1; i++) {
      ans += calc(coord[permu[i]], coord[permu[i + 1]]);
    }

  } while (next_permutation(permu.begin(), permu.end()));

  printf("%.11lf", ans / fact(n));
  cout << endl;

  // cout << fact(n) << endl;
}
