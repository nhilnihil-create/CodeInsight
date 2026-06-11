#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;

  int start = N;
  vector<int> answer;
  while (start > 0) {
    int check = max(0, start - M);
    while (S[check] == '1') check++;
    if (check == start) {
      cout << -1 << endl;
      return 0;
    }
    answer.emplace_back(start - check);
    start = check;
  }

  reverse(answer.begin(), answer.end());
  rep(i, (int)answer.size()) {
    if (i != 0) cout << " ";
    cout << answer[i];
  }
  cout << endl;
  return 0;
}
