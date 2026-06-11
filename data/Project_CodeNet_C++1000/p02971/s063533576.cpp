#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> data(N);
  int max, semimax;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    data.at(i) = a;
    if(i == 0) {
      max = a;
    }
    else if(i == 1) {
      if(a > max) {
        semimax = max;
        max = a;
      }
      else {
        semimax = a;
      }
    }
    else if(a > max) {
      semimax = max;
      max = a;
    }
    else if(a > semimax) {
      semimax = a;
    }
  }
  for(int i = 0; i < N; i++) {
    if(data.at(i) != max) {
      cout << max << endl;
    }
    else {
      cout << semimax << endl;
    }
  }
}