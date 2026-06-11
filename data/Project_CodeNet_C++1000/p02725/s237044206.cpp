#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, N, p;
  cin >> K >> N;
  vector<int> A(N+1);
  for (int i=1; i<=N; i++) {
    cin >> p;
    A[i]=p;
    A[0]=p;
  }
  int m=0;
  for (int i=1; i<=N; i++) {
    if (i==1) {
      m=K-(A[0]-A[1]);
    }
    else {
      m=max(m, A[i]-A[i-1]);
    }
  }
  cout << K-m << endl;
}