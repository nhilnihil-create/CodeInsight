#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

vector<int> x(10), y(10);

double distance(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return sqrt(dx * dx + dy * dy);
  // return pow(dx * dx + dy * dy, 0.5);
}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> x[i] >> y[i];
  }

  // 点（町）の順番の配列を0〜N-1番まで作成
  vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    v[i] = i + 1;
  }

  // 階乗の計算
  int cnt = 1;
  for (int i = 1; i <= N; ++i) cnt *= i;

  // 今いる町v[i]から、次の町v[i+1]までの距離を求め、総和（dis_sum）を計算。
  // next_permutation()で順列の総数分（vの組み合わせを変え、trueを返すので）繰り返す。
  double dis_sum = 0.0;
  do {
    for (int i = 0; i < N - 1; ++i) {
      dis_sum += distance(v[i], v[i + 1]);
    }
  } while (next_permutation(v.begin(), v.end()));

  // 浮動小数点10桁までの精度で「距離の平均」を出力。
  cout << setprecision(10) << dis_sum / cnt << endl;
  return 0;
}