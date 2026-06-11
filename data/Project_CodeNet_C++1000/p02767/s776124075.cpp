#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  int ans = 1000000;
  for(int i = 1; i <= 100; i++) {
    int sum = 0;
    for(int j = 0; j < N; j++) {
      sum += (vec.at(j) - i) * (vec.at(j) - i);
    }
    if(sum < ans) {
      ans = sum;
    }
  }
  cout << ans << endl;
}