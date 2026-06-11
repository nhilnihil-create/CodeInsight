#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string N;
  cin >> N;
  int M = N.size();
  vector<vector<int>> answer(M+1, vector<int>(2));
  answer[M][0] = 0;
  answer[M][1] = 1;
  for (int i = M - 1; i >= 0; --i) {
    int num = (N[i] - '0');
    answer[i][0] = min(answer[i+1][0] + num, answer[i+1][1] + (10 - num));
    answer[i][1]  = min(answer[i+1][0] + num + 1, answer[i+1][1] + (10 - num - 1));
  }
  cout << answer[0][0] << endl;
  return 0;
}
