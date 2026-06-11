#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> W(N);
  vector<int> memo(N);
  cin >> W.at(0);
  memo.at(0) = W.at(0);
  for (int i = 1; i < N; i++) {
    cin >> W.at(i);
    memo.at(i) = memo.at(i - 1) + W.at(i);
  }
  int memo2 = abs(memo.at(N - 1) - memo.at(0)- memo.at(0)), memo3 = abs(memo.at(N - 1) - memo.at(1) - memo.at(1));
  for (int i = 0; i < N - 1; i++) {
    if (memo.at(i) < memo.at(N - 1) / 2) {
      memo2 = abs(memo.at(N - 1) - memo.at(i) - memo.at(i));
      memo3 = abs(memo.at(N - 1) - memo.at(i + 1) - memo.at(i + 1));
    }
    else {
      break;
    }
  }
  cout << min(memo2, memo3) << endl;
}