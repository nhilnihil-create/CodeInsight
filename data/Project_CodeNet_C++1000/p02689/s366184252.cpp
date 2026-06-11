#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

int main() {
  i64 N, M;
  cin >> N >> M;
  vector<i64> H(N);
  for (i64 i = 0; i < N; i++) {
    cin >> H[i];
  }
  vector<i64> Good(N, 1);
  for (i64 i = 0; i < M; i++) {
    i64 a, b;
    cin >> a >> b;
    if (H[a-1] > H[b-1]) {
      Good[b-1] = 0;
    } else if(H[a-1] < H[b-1]) {
      Good[a-1] = 0;
    } else {
      Good[b-1] = Good[a-1] = 0;
    }
  }
  i64 r;
  r = accumulate(Good.begin(), Good.end(), 0);
  cout << r << endl;
}
