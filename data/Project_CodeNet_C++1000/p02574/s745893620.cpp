#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
  int a = max(x, y);
  int b = min(x, y);
  if(a % b == 0) {
    return b;
  }
  else {
    return gcd(b, a % b);
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<bool> judge(1000000, false);
  bool stop = false;
  for(int i = 0; i < N; i++) {
    int x = A.at(i);
    for(int j = 2; j * j <= A.at(i); j++) {
      if(x % j == 0) {
        if(judge.at(j - 1)) {
          stop = true;
          break;
        }
        else {
          judge.at(j - 1) = true;
          while(x % j == 0) {
            x /= j;
          }
        }
      }
    }
    int64_t y = x;
    int64_t z = A.at(i);
    if(y * y > z) {
      if(judge.at(x - 1)) {
        stop = true;
      }
      else {
        judge.at(x - 1) = true;
      }
    }
    if(stop) {
      break;
    }
    if(i == N - 1) {
      cout << "pairwise coprime" << endl;
      return 0;
    }
  }
  int keep = gcd(A.at(0), A.at(1));
  for(int i = 2; i < N; i++) {
    keep = gcd(keep, A.at(i));
  }
  if(keep == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }
  cout << "not coprime" << endl;
}