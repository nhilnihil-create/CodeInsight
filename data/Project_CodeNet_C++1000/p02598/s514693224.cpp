#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int n, k;

bool C(vector<int> a, double x) {
  int kaisuu = 0;
  for (int el : a) kaisuu += (el - 1) / x;
  return kaisuu <= k;
}

int main() {
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  double lb = 0, ub = INF;

  for (int i = 0; i < 100; i++) {
    double mid = (lb + ub) / 2;
    if (C(a, mid))
      ub = mid;
    else
      lb = mid;
  }

  cout << (int)(floor(lb) + 1) << endl;
  return 0;
}