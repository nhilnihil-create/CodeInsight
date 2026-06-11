#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, M;
  cin >> N;
  cin >> M;
  
  int votes = 0;
  vector <int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    votes += A[i];
  }
  
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] >= votes / (float)(4 * M)) cnt++;
  }
  
  if (cnt >= M) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}