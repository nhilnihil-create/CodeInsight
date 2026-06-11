#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define erep(i,n) for(int i=1; i<=(n); i++)
using namespace std;

vector<int> x(10), y(10);

double distance(int i, int j) {
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  return pow(dx * dx + dy * dy, 0.5);
}

int main() {
  int N;
  cin >> N;
  erep(i,N) {
    cin >> x[i] >> y[i];
  }

  vector<int> v(N);
  rep(i,N) {
    v[i] = i + 1;
  }

  int cnt = 1;
  erep(i,N) {
    cnt *= i;
  }

  double dis_sum = 0.0;
  do {
    for (int i = 0; i < N - 1; ++i) {
      dis_sum += distance(v[i], v[i + 1]);
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << setprecision(10) << dis_sum / cnt << endl;
  return 0;
}