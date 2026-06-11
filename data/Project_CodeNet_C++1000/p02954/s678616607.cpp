#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> ans(N, 0);
  int count = 1;
  for(int i = 0; i < N - 1; i++) {
    if(S.at(i) == S.at(i + 1)) {
      count++;
    }
    else if(S.at(i) == 'R') {
      ans.at(i) += (count + 1) / 2;
      ans.at(i + 1) += count / 2;
      count = 1;
    }
    else {
      ans.at(i - count + 1) += (count + 1) / 2;
      ans.at(i - count) += count / 2;
      count = 1;
    }
  }
  ans.at(N - 1 - count) += count / 2;
  ans.at(N - 1 - count + 1) += (count + 1) / 2;
  for(int i = 0; i < N; i++) {
    cout << ans.at(i) << " ";
  }
  cout << endl;
}