#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N;
  M=N*100/108;
  if (M*108/100==N) {
    cout << M << endl;
  }
  if ((M+1)*108/100==N) {
    cout << M+1 << endl;
  }
  if (M*108/100!=N&&(M+1)*108/100!=N) {
    cout << ":(" << endl;
  }
}
