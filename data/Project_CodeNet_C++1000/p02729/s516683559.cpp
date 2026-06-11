#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  if(N>=2 && M>=2) {
    cout << N*(N-1)/2 + M*(M-1)/2 << endl;
  }
  else if(N>=2 && M<2) {
    cout << N*(N-1)/2 << endl;
  }
  else if(N<2 && M>=2) {
    cout << M*(M-1)/2 << endl;
  }
  else cout << 0 << endl;
  
}