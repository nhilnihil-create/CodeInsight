#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int64_t sum=0;
  cin >> N;
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
  cin >> vec.at(i);
  }
  for (int i = 0; i < N; i++) {
    sum = (sum ^ vec.at(i));
  }
  for (int i = 0; i < N; i++) {
    cout << (sum ^ vec.at(i)) << " ";
  }
  cout << endl;
}
