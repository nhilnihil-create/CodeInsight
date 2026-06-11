#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<long> H(N); 
  long maxH = 0;
  bool check = false;
  for (int i =0; i<N; i++) {
    cin >> H.at(i);
    maxH = max(H.at(i),maxH);
    if (maxH - H.at(i) >= 2) {
      check = true;
      break;
    }
  }
  if (check) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  } 
}