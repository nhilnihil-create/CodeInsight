#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> res(N, 1);
  for (int i = 0; i < M; ++i) {
    int d; cin >> d;
    for (int j = 0; j < d; ++j) {
      int a; cin >> a; --a;
      res[a] = 0;
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; ++i) if (res[i]) ++cnt;
  cout << cnt << endl;
}
