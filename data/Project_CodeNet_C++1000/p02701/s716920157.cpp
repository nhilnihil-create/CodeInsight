#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> vec(N);
  string S;
  for (int i = 0; i < N; i++) {
    cin >> S;
    vec.at(i) = S;
  }
  sort(vec.begin(), vec.end());
  int counter = 1;
  for (int i = 1; i < N; i++) {
    if (vec.at(i) == vec.at(i-1))
      continue;
    if (vec.at(i) != vec.at(i-1))
      counter++;
  }
  cout << counter << endl;
}