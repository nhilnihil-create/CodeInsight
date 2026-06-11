#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;
    vec.at(A - 1) = i + 1;
  }
  for(int i = 0; i < N; i++) {
    if(i != N - 1) {
      cout << vec.at(i) << " ";
    }
    else {
      cout << vec.at(N - 1) << endl;
    }
  }
}