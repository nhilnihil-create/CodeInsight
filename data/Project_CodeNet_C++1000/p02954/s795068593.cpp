#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int N = static_cast<int>(S.size());
  vector<int> A(N, 1);
  int l = 0;
  for (int i = 1; i < N; ++i) {
    if ((S[i - 1] == 'R') && (S[i] == 'R')) {
      A[i + 1] += A[i - 1];
      A[i - 1] = 0;
    } else if ((S[i - 1] == 'R') && (S[i] == 'L')) {
      l = i;
    } else if ((S[i - 1] == 'L') && (S[i] == 'L')) {
      A[l - ((i - l) & 1)] += A[i];
      A[i] = 0;
    }
  }
  const char* sep = "";
  for (int i = 0; i < N; ++i) {
    cout << sep << A[i];
    sep = " ";
  }
  cout << endl;
  return 0;
}
