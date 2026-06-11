#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> data(N);
  for(int i = 0; i < N; i++) {
    cin >> data.at(i);
  }
  vector<int> ans(N);
  int count = 0;
  for(int i = N - 1; i >= 0; i--) {
    int sum = 0;
    for(int j = 2; j * (i + 1) - 1 < N; j++) {
      sum += ans.at(j * (i + 1) - 1);
    }
    sum %= 2;
    ans.at(i) = (data.at(i) + sum) % 2;
    if(ans.at(i) == 1) {
      count++;
    }
  }
  cout << count << endl;
  for(int i = 0; i < N; i++) {
    if(ans.at(i) == 1) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}