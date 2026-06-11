#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, Q;
  long long K;
  
  cin >> N >> K >> Q;
  
  vector<int> queue(N, -Q);
  
  for (int i = 0; i < Q; i++) {
    int in;
    
    cin >> in;
    
    queue[in - 1]++;
  }
  
  for (int i = 0; i < N; i++) {
    if (K + queue[i] > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  
  return 0;
}
