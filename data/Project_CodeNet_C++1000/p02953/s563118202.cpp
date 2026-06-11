#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  bool ok = true;
  reverse(H.begin(), H.end());
  for (int i = 0; i < N - 1; i++) {
    if (H.at(i + 1) - H.at(i) == 1) {
      H.at(i + 1)--;
    }
    if (H.at(i + 1) - H.at(i) > 1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
      
}