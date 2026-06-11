#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> v(N);
  int d, ex;
  for (int i = 0; i < K; i++) {
    cin >> d;
    for (int j = 0; j < d; j++) {
      cin >> ex;
      v[ex - 1] = true;
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
      if(v[i]==false) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
