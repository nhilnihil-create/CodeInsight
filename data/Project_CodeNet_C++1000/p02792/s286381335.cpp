#include <bits/stdc++.h>
using namespace std;

          

int main() {
  int N;
  cin >> N;
  vector<vector<int>> data(10, vector<int> (10));
  for(int i = 1; i <= N; i++) {
    int a = i % 10;
    int b = i;
    while(b >= 10) {
      b /= 10;
    }
    data.at(b).at(a)++;
  }
  int ans = 0;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      ans += data.at(i).at(j) * data.at(j).at(i);
    }
  }
  cout << ans << endl;
}