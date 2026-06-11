#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum = 0;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      for(int k = j + 1; k < N; k++) {
        if(vec.at(i)==vec.at(j)||vec.at(j)==vec.at(k)||vec.at(k)==vec.at(i))
          continue;
        if(vec.at(i) < vec.at(j) + vec.at(k) && vec.at(i) > abs(vec.at(j) - vec.at(k)))
          sum++;
      }
    }
  }
  cout << sum << endl;
}