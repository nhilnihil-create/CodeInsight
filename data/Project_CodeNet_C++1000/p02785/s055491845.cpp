#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
    vector<int> vec(N);
  int H;
  for (int i = 0; i < N; i++) {
    cin >> H;
    vec.at(i) = H;
  }
  sort(vec.begin(), vec.end(), greater<int>());
  long long Ans = 0;
  if (N <= K)
    cout << 0 << endl;
  else {
    for (int i = 0; i < K; i++)
      vec.at(i) = 0;
    for (int i = 0; i < N; i++)
      Ans += vec.at(i);
    cout << Ans << endl;
  }
}
