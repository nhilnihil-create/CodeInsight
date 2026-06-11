#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,Q; long K;
  cin >> N >> K >> Q;
  vector<int> A(Q);
  vector<long> win(N);
  for (int i =0; i<Q; i++) {
    int a; cin >> a; A.at(i) = a;
    win.at(a-1)++;
  }
  
  for (int i =0; i<N; i++) {
    if (K - Q + win.at(i) > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}