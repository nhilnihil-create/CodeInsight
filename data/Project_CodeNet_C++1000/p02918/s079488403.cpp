#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  int count = 0;
  for(int i = 0; i < N - 1; i++) {
    if(S.at(i) == 'R' && S.at(i + 1) == 'L') {
      count++;
    }
  }
  int edge = 0;
  if(S.at(0) == 'L') {
    edge++;
  }
  if(S.at(N - 1) == 'R') {
    edge++;
  }
  if(count >= K) {
    cout << N - 2 * count - edge + 2 * K << endl;
  }
  else {
    cout << N - 1 << endl;
  }
}