#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> dam(N);
  vector<int64_t> mount(N);
  for(int i = 0; i < N; i++) {
    cin >> dam.at(i);
  }
  int64_t sum = 0;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      sum += dam.at(i);
    }
    else {
      sum -= dam.at(i);
    }
  }
  mount.at(0) = sum;
  for(int i = 1; i < N; i++) {
    mount.at(i) = 2 * (dam.at(i - 1) - mount.at(i - 1) / 2);
  }
  for(int i = 0; i < N; i++) {
    cout << mount.at(i) << endl;
  }
}