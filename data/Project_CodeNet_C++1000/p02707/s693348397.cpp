#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int A;
  vec.at(0) = 0;
  for (int i = 1; i < N; i++) {
    cin >> A;
    vec.at(i) = A;
  }
  sort(vec.begin(), vec.end());
  int counter;
  int start = 0;
  for (int i = 0; i < N; i++) {
    counter = 0;
    for (int j = start; j < N; j++) {
      if (vec.at(j) == i+1)
        counter++;
      if (vec.at(j) > i+1)
        break;
    }
    cout << counter << endl;
    start += counter;
  }
}
