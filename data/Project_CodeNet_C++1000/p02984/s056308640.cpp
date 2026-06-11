#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<int> rain(N, 0); // 2つ前の山との降水量の差
  for (int i = 0; i < N-2; i++) rain[i+2] = (A[i+1] - A[i])*2;
  rain[1] = (A[0] - A[N-1])*2;
  int sub = rain[1];
  for (int i = 0; i < N; i+=2) sub += rain[i];
  int Rain = A[0] - (sub/2); // 山1の降水量
  vector<int> ans(N, Rain);
  int tmp = 0;
  for (int i = 0; i < N; i+=2) {
    tmp += rain[i];
    ans[i] += tmp;
  }
  for (int i = 1; i < N-1; i+=2) {
    tmp += rain[i];
    ans[i] += tmp;
  }
  for (int i = 0; i < N; i++) cout << ans[i] << " ";
  cout << endl;
}
