#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// 計算効率が良い方法も自力で実装できるが、趣旨的に全探索で実装する
vector<int> x, y;
double dist(int i, int j) {
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return pow(dx * dx + dy * dy, 0.5);
}

int main() {
  int n;
  cin >> n;

  rep(i, n) {
    int a, b;
    cin >> a >> b;
    x.push_back(a);
    y.push_back(b);
  }
  
  vector<int> v(n);
  for(int i = 0; i < n; i++) v[i] = i;

  double ans = 0.0;
  do {
    for(int i = 0; i < n - 1; i++) ans += dist(v[i], v[i + 1]);
  } while(next_permutation(v.begin(), v.end()));
  int Factorial = 1;
  for(int i = 2; i <= n; i++) Factorial *= i;
  ans /= Factorial;

  printf("%.10f\n", ans);
  return 0;
}
