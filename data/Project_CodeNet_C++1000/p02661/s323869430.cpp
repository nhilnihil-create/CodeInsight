#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0;i < (int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

int med(int N, vector<int> x) {
  if (N % 2 == 0) {
    return x[N / 2 - 1] + x[N / 2];
  } else {
    return x[(N - 1) / 2];
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  REP(i, N) {
    cin >> a[i] >> b[i];
  }
  sort(ALL(a));
  sort(ALL(b));
  cout << med(N, b) - med(N, a) + 1 << endl;
}